#!/usr/bin/env bash

# Script for running proto-typed tests and checking the results

function print_help {
    printf "Proto-typed test suite.\nUsage: bash $0\n" 
}

PTC="ptc"
PT="pt"
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
    CMD="$PT see ${TEST_DIR}$1"
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
false\ntrue\ntrue\nfalse\ntrue\nProto-otorP
accgtatg\ngtatgcca
4, 4\ntrue, true, true\n" "expressions"
}

function test_maybes {
    expect_pass "maybes.pt" "maybes"
    expect_out_eq "8\n9\n5\n42\nthere\ngeneral\n50\n1
true\n48\n6.2\nnone\ntrue\n48\n6.2\nnone
0\ntrue\n0\nfalse\ntrue\ntrue\n" "maybes"
}

function test_any {
    expect_pass "any.pt" "any"
    expect_out_eq "hello\nhi\ntrue\n99\n5.25\n5.25\nstr\nstr\nno\n7542\n0\n8\nhi\n6\ntrue\n-0
no\nno\nyes\n" "any"
}

function test_structs {
    expect_pass "structs.pt" "structs"
    expect_out_eq "1\n0\n42
hello
-99
true
40.5
4 true 4.25 hi
49f\n3.14\ntrue\nfalse\ntrue\nfalse
true\nfalse\ntrue\ntrue\nfalse
4.05\n3-7trueha\n4\ntrue
true\nfalse\ntrue\ntrue\nfalse
none\nnot none\nnot none\n" "structs"
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
true\nfalse\nfalse\nfalse\nfalse\ntrue\nfalse\nfalse\ntrue
4\n1\n3\n-1\n5\n-1\n1\n1\n0\n-1\n-1\n1\ntrue\ntrue\ntrue\nfalse
0.5 0.5 \n3.5 3.5 3.5 \n5.5 \n4.5 \ntrue\nfalse\ntrue\ntrue\nfalse
true\nfalse\n0 1 2 3 4 5 6 7 8 \n1 2 \n3 4 \n5 6 \n-
4 5 \n1\n1 2 3 -10 -8 6 -9 \nnone\nnone\n1 2 \n1 2 3 4 5 \n1 2 3 4 5 \n" "arrays"
}

function test_statements {
    expect_pass "statements.pt" "statements"
    expect_out_eq "3 2 1 4\n0 1 2 3 \n5 4 3 2 \n10 7 4 1 \na b c \n-4 -2 0 \nhi there
10\n10\n" "statements"
}

function test_casting {
    expect_pass "casting.pt" "casting"
    expect_out_eq "String\n42\n0.5\ntrue\nString\n42\n0.5\ntrue
false\nfalse\ntrue\ntrue\n4\ntrue\n0\nfalse\n11110
2.42\n3.14159\n-7\n31\n2.42\n3.14159\n-7\n31\n" "casting"
}

function test_floats {
    expect_pass "floats.pt" "floats"
    expect_out_eq "true\ntrue\nfalse\ntrue\nfalse\n" "floats"
}

function test_ptlib_strings {
    expect_pass "ptlib_strings.pt" "ptlib_strings"
    expect_out_eq "HELLO THERE 32\ner sfd 43 ]}{\trp;[]+455\n55\n33\n108\nd*?\n94
keram\n4\n-1\nfalse\ntrue\nProto-otorP\ntrue\n34\n42\nnone\n42\n42\nnone\n11\n-79
0.42\nnone\n-42\n3.14159\nnone\nnone\n" "ptlib_strings"
}

function test_ptlib_arrays {
    expect_pass "ptlib_arrays.pt" "ptlib_arrays"
    expect_out_eq "sushi like I \n9 8 7 \n6 5 4 \n3 2 1 \n1.5 1.5 \n3.5 3.5 3.5 \n5.5 \n3
0 1 2 3 4 5 6 7 8 \n1 2 \n3 4 \n5 6 \n2 4 5 6 7 8 \n1 2 3 \n1,2,3,4,5,
0,1,2,3,4,5,6,7,\n?,a,b,c,\n" "ptlib_arrays"
}

function test_ptlib_sort {
    expect_pass "ptlib_sort.pt" "ptlib_sort"
    expect_out_eq "[10, 20, 30, 40, 50]
[10, 20, 30, 40, 50]\n[50, 40, 30, 20, 10]\n[]\n[0]
[-994, -8, 0, 0, 0, 1, 1515]\n[false, false, true, true, true]
[-5, 1, 64.5]\n[-inf, -99, -5, 1, 64.5, inf]\n" "ptlib_sort"
}

function test_ptlib_math {
    expect_pass "ptlib_math.pt" "ptlib_math"
    expect_out_eq "is NaN\nis really not NaN\n4\n3\n4\n3e-08
15\n-3\n15.9\n-3.5\n2\n1\n14\n20\n10\n18\n526
4\n84\n168\n0\n0\n2984671872\n2137903735020
0.9932517730102834\n0\n3\ninf\n-nan\n0.4313637641589874\ninf\n-nan\n" "ptlib_math"
}

function test_ptlib_env {
    expect_pass "ptlib_env.pt" "ptlib_env"
    expect_out_eq "true\nthere!\n" "ptlib_env"
}

function test_ptlib_io {
    touch testinempty.txt
    printf "Lorem Ipsum\nAnd some other stuff\n3rd line" > testin.txt

    expect_pass "ptlib_io.pt -- A Black Cat" "ptlib_io"
    expect_out_eq "A\nBlack\nCat\ntrue\ntrue\ntrue\ntrue\ntrue
Lorem Ipsum\nAnd some other stuff\n3rd line\n0\nL\n" "ptlib_io"

    # Cleanup
    rm -f test1.txt
    rm -f testinempty.txt
    rm -f testin.txt
}

function test_var {
    expect_pass "var.pt" "var"
    expect_out_eq "4\n2.2\nHello\n1\ntruefalse\n5.52.2\nab\n-8\n" "var"
}

function test_numbers {
    expect_pass "numbers.pt" "numbers"
    expect_out_eq "42, 42, 42, 42\n-42, -42, -42, -42
3.14159265, 6.02214076e+23, -2.2e-07
-3.14159265, 6.02214076e+23, 2200000000
3, 1e-09\n" "numbers"
}

function test_funvar {
    expect_pass "funvar.pt" "funvar"
    expect_out_eq "4\n-4\nnot 8\n16\ntrue\n49\ntrue\n49\ntrue
not 3\n6\nnot 10\n20\nfalse
Error: Oops!\nOh, no!
4\n-4\nnot 8\n16\nnot 3\n6\nnot 10\n20\n" "funvar"
}

function test_array_resolver {
    expect_pass "array_resolver.pt" "array_resolver"
    expect_out_eq "[[[1,2,3,][4,5,6,][]]]
[[[]]]
[[[][]][[][]][[][]]]
[[[5,][][][8,4,]][[]]]
[[][][]]
[[ab,]]
[[][][hm,okay,][]]\n" "array_resolver"
}

function test_maybe_type_arrays {
    expect_pass "maybe_type_arrays.pt" "maybe_type_arrays"
    expect_out_eq "0 89 -9 8 42 \ntrue\nfalse
42 8 \n9\nnone\ntrue\nfalse\n?\na\nb\n0\n1\n2\n" "maybe_type_arrays"
}

function test_hash_table {
    expect_pass "hash_table.pt" "hash_table"
    expect_out_eq "marek: 42\nmatej: 1048\nlukas: 1\npatrik: 6\n" "hash_table"
}

function test_decimal {
    expect_pass "decimal.pt" "decimal"
    expect_out_eq "314159265/100000000 = 3.14159265
-2099114855/700000000 = -2.998735507142857\n100000000/700000000 = 0.1428571428571428
-2099114855/700000000 = -2.998735507142857\n419822971/-140000000 = -2.998735507142857
1/8 = 0.125\n1/8 = 0.125\n105975/7488 = 14.15264423076923\n785/96 = 8.177083333333334
8/125 = 0.064\n8/125 = 0.064\n8/3 = 2.666666666666667
true\ntrue\nfalse\ntrue\nfalse\ntrue\n" "decimal"
}

function test_old_bugs {
    expect_pass "old_bugs.pt" "old_bugs"
    expect_out_eq "false\ntrue\ntrue\n1234\ntrue\nno\n8\n4\n321\nhi\n6.6\ntrue\nff\n42\nexpr string\n" "old_bugs"
}

function test_const_folding {
    expect_pass "const_folding.pt" "const_folding"
    expect_out_eq "42, 42\n8, 18, 8\n0.5, 0.25, 0.75\n1, 4, 2
true, true, false, true
false, true, false, true
true, true, false, false
true, true, false, false
8, 9, 0\nfalse, true\nI like ptc
-1, 0\nfalse, true\n1,2,3,\ntrue,false,
1, -3, false, m, none\n" "const_folding"
}

# Expect fail tests

function test_missing_return {
    expect_fail "xfails/missing_return.pt" "Missing return in a flow path in a function ‘miss’" "missing_return"
}

function test_nested_fun {
    expect_fail "xfails/nested_fun.pt" "Nested functions are not allowed." "nested_fun"
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
    run_test ptlib_arrays
    run_test ptlib_sort
    run_test ptlib_math
    run_test ptlib_env
    run_test ptlib_io
    run_test var
    run_test numbers
    run_test funvar
    run_test array_resolver
    run_test maybe_type_arrays
    run_test hash_table
    run_test decimal
    run_test old_bugs
    run_test const_folding

    # Expect fail tests
    run_test missing_return
    run_test nested_fun
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
