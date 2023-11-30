#!/usr/bin/env bash

# Script for running proto-typed tests and checking the results

function print_help {
    printf "Proto-typed test suite.\nUsage: bash $0\n" 
}

PTC="ptc"
PT="../run_pt.sh"
OUTP_ERR=/tmp/.ptc_test_err.txt
OUTP_STD=/tmp/.ptc_test_std.txt
TEST_DIR=""
WRKDIR="./"
POSITIONAL_ARGS=()

while [[ $# -gt 0 ]]; do
    case $1 in
        -h|--help)
            print_help
            exit 256
            ;;
        -ptc)
            PTC="$2"
            shift
            shift
            ;;
        -pt)
            PT="$2"
            shift
            shift
            ;;
        -dir)
            WRKDIR="$2"
            shift
            shift
            ;;
        -test-dir)
            TEST_DIR="$2"
            shift
            shift
            ;;
        *)
            echo "ERROR: Unknown argument: '$1'"
            exit 1
            #POSITIONAL_ARGS+=("$1")
            #shift
            ;;
    esac
done

set -- "${POSITIONAL_ARGS[@]}" # restore positional parameters

FAILED_TESTS=""
INDEX=0
C_OFF='\033[0m'
C_RED='\033[0;31m'
C_GREEN='\033[0;32m'

function failed {
    FAILED_TESTS+=" $1"
    printf "${C_RED}FAIL${C_OFF}: $1: $2\n"
}

function run {
    objf=()
    for of in ${@:2:$#-1}
    do
        objf+=(${TEST_DIR}$of)
    done
    CMD="$PT ${TEST_DIR}$1 0 $WRKDIR $objf"
    $CMD 2>$OUTP_ERR 1>$OUTP_STD
    RETCODE=$(echo $?)
    # Get output binary name
    PROGNAME=$(echo "$1" | cut -f 1 -d '.')".out"
    rm -f ${TEST_DIR}${PROGNAME}
    rm -f $objf
}

function expect_pass {
    run "${@:1:$#-1}"
    if [[ $RETCODE -ne 0 ]]; then
        failed "${@: -1}" "Compilation failed."
        printf "Command:\n--------\n$CMD\n"
        printf "Output:\n-------\n"
        cat $OUTP_STD
        printf "Error output:\n-------------\n"
        cat $OUTP_ERR
    fi
}

function expect_fail {
    run $1
    local errmsg=$(cat "$OUTP_ERR")
    if [[ $RETCODE -eq 0 ]]; then
        failed $3 "Test was supposed to fail, but passed."
    elif ! [[ "$errmsg" =~ "$2" ]] ; then
        failed $3 "Error message differs."
        printf "Command:\n--------\n$CMD\n"
        printf "Output:\n-------\n"
        cat $OUTP_STD
        printf "Error output:\n-------------\n"
        cat $OUTP_ERR
        printf "Expected error regex:\n--------------\n${2}\n"
    fi
}

function expect_out_eq {
    outstr=$(cat $OUTP_STD)
    if ! cmp  "$OUTP_STD" <(printf "$1") ; then
        failed $2 "Output differs"
        printf "Expected:\n-------\n${1}\n"
        printf "Got:\n----\n${outstr}\n"
    fi
}

function testnum {
    printf "[${INDEX}/${TEST_AMOUNT}]"
}

function run_test {
    let "INDEX=INDEX+1"
    failed_am=${#FAILED_TESTS}
    printf "$(testnum) ${1}: Running\n"
    test_"$1"
    failed_now=${#FAILED_TESTS}
    if [[ $failed_now -eq $failed_am ]]; then
        printf "$(testnum) ${1}: ${C_GREEN}OK${C_OFF}\n"
    else
        printf "$(testnum) ${1}: ${C_RED}FAILED${C_OFF}\n"
    fi
}

function test_fib {
    expect_pass "fib.pt" "fib"
    expect_out_eq "55" "fib"
}

function test_strings {
    expect_pass "strings.pt" "strings"
    expect_out_eq "global string
expr string
local s
a='hello', b='': a != b
a='hello', b='': a != b
a='hello', b='hello': a == b
a='hello', b='hello': a == b
a='hello', b='hell': a != b
a='hello', b='hell': a != b
a='hello', b='helló': a != b
a='hello', b='helló': a != b
a='helló', b='helló': a == b
a='helló', b='helló': a == b
a='there', b='': a > b
a='', b='there': a <= b
a='aaabb', b='aaaab': a > b
a='aaabb', b='aaabb': a <= b
a='there', b='': a >= b
a='', b='there': a < b
a='aaabb', b='aaabb': a >= b
a='', b='': a >= b
a='there', b='': a >= b
a='a', b='z': a < b
a='our', b='out': a < b
a='there', b='': a > b
a='ahoj', b='ahoj': a <= b
a='our', b='out': a <= b
" "strings"
}

function test_expressions {
    expect_pass "expressions.pt" "expressions"
    expect_out_eq "4\n4\n-110.5\n-110.5\ntrue\ntrue\ntruman\ntrue\nfalse\n(0 - 3), 0, 1, 2, 3
-1\n-43\ntrue\nfalse
2\n0\n-1\n-616\n672\n2\n4\n16
false\ntrue\ntrue\nfalse\ntrue\n" "expressions"
}

function test_maybes {
    expect_pass "maybes.pt" "maybes"
    expect_out_eq "8\n9\n5\n42\nthere\ngeneral\n50\n1
true\n48\n6.2\nnone\ntrue\n48\n6.2\nnone\n" "maybes"
}

function test_any {
    expect_pass "any.pt" "any"
    expect_out_eq "hello\nhi\ntrue\n99\n5.25\n5.25\nstr\nstr\nno\n7542\n0\n8\nhi\n6\ntrue\n-0\n" "any"
}

function test_structs {
    expect_pass "structs.pt" "structs"
    expect_out_eq "1\n0\n42
hello
-99
true
40.5
4 true 4.25 hi
49f\n3.14\n" "structs"
}

function test_modules {
    expect_pass "modules.pt" "modules2.o" "modules"
    expect_out_eq "42\ntrue\n0.2\nhi\n2\n-99\n10\n0\nIn _entry\n" "modules"
}

function test_empty {
    expect_pass "empty.pt" "empty"
    expect_out_eq "" "empty"
}

function test_arrays {
    expect_pass "arrays.pt" "arrays"
    expect_out_eq "43 44 45 \n3 2 1 false true true 0 1.5 2.6 \nLet's find out \ntrue
false\nfalse\ntrue\nfalse\n" "arrays"
}

function test_statements {
    expect_pass "statements.pt" "statements"
    expect_out_eq "3 2 1 4\n0 1 2 3 \n5 4 3 2 \n10 7 4 1 \na b c \n-4 -2 0 \nhi there\n" "statements"
}

function test_casting {
    expect_pass "casting.pt" "casting"
    expect_out_eq "String\n42\n0.5\ntrue\nString\n42\n0.5\ntrue
false\nfalse\ntrue\ntrue\n4\ntrue\n0\nfalse\n11110\n" "casting"
}

function test_floats {
    expect_pass "floats.pt" "floats"
    expect_out_eq "true\ntrue\nfalse\ntrue\nfalse\n" "floats"
}

function test_ptlib_strings {
    expect_pass "ptlib_strings.pt" "ptlib_strings"
    expect_out_eq "HELLO THERE 32\ner sfd 43 ]}{\trp;[]+455\n55\n33\n108\nd*?\n94
keram\n4\n-1\nfalse\ntrue\n" "ptlib_strings"
}

# Expect fail tests

function test_missing_return {
    expect_fail "missing_return.pt" "Missing return in a flow path in a function ‘miss’" "missing_return"
}

function run_all_tests {
    run_test fib
    run_test strings
    run_test expressions
    run_test maybes
    run_test any
    run_test structs
    run_test modules
    run_test empty
    run_test arrays
    run_test statements
    run_test casting
    run_test floats
    run_test ptlib_strings

    # Expect fail tests
    run_test missing_return
}

# Count all functions starting with test_ 
TEST_AMOUNT=$(declare -F | grep "test_" | wc -l)
start_time=`date +%s`
run_all_tests
if [ ! -z "$FAILED_TESTS" -a "$FAILED_TESTS" != " " ]; then
    UNQ_TST=""
    failedam=0
    for i in $FAILED_TESTS; do
        if ! [[ ${UNQ_TST} =~ $i ]]
        then
            UNQ_TST+=" $i"
            ((++failedam))
        fi
    done
    printf "${C_RED}FAILED${C_OFF}: ${failedam} test(s) did not pass\n"
    printf "Failed tests:\n"
    for t in $UNQ_TST; do
        printf "\t${t}\n"
    done
else
    end_time=`date +%s`
    runtime=$((end_time-start_time))
    printf "${C_GREEN}SUCCESS${C_OFF}: $INDEX tests passed (after $runtime s)\n"
fi
