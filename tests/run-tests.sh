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

FAILED_TESTS=()
INDEX=0
C_OFF='\033[0m'
C_RED='\033[0;31m'
C_GREEN='\033[0;32m'

function failed {
    FAILED_TESTS+=("$1")
    printf "${C_RED}FAIL${C_OFF}: $1: $2\n"
    
}

function run {
    CMD="$PT ${TEST_DIR}$1 0 $WRKDIR"
    $CMD 2>$OUTP_ERR 1>$OUTP_STD
    RETCODE=$(echo $?)
    # Get output binary name
    PROGNAME=$(echo "$1" | cut -f 1 -d '.')".out"
    rm -f ${TEST_DIR}${PROGNAME}
}

function expect_pass {
    run $1
    if [[ $RETCODE -ne 0 ]]; then
        failed $2 "Compilation failed."
        printf "Command:\n--------\n$CMD\n"
        printf "Output:\n-------\n"
        cat $OUTP_STD
        printf "Error output:\n-------------\n"
        cat $OUTP_ERR
    fi
}

function expect_fail {
    run $1
    if [[ $RETCODE -eq 0 ]]; then
        failed $3 "Test was supposed to fail, but passed."
    elif ! cmp -s "$OUTP_ERR" <(printf "$2") ; then
        failed $3 "Error message differs."
        printf "Command:\n--------\n$CMD\n"
        printf "Output:\n-------\n"
        cat $OUTP_STD
        printf "Error output:\n-------------\n"
        cat $OUTP_ERR
        printf "Expected error:\n--------------\n${2}\n"
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
    failed_am=${#FAILED_TESTS[@]}
    printf "$(testnum) ${1}: Running\n"
    test_"$1"
    failed_now=${#FAILED_TESTS[@]}
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
2\n0\n-1\n-616\n672\n"
}

function test_maybes {
    expect_pass "maybes.pt" "maybes"
    expect_out_eq "8\n9\n5\n42\nthere\ngeneral\n50\n1\n"
}

function test_missing_return {
    expect_fail "missing_return.pt" "<unknown>:0: error: Missing return in a flow path in a function ‘miss’.\n" "missing_return"
}

function run_all_tests {
    run_test fib
    run_test strings
    run_test missing_return
    run_test expressions
    run_test maybes
}

# Count all functions starting with test_ 
TEST_AMOUNT=$(declare -F | grep "test_" | wc -l)
start_time=`date +%s`
run_all_tests
if [[ ${#FAILED_TESTS[@]} -ne 0 ]]; then
    UNQ_TST=($(printf "%s\n" "${FAILED_TESTS[@]}" | sort -u | tr '\n' ' '))
    printf "${C_RED}FAILED${C_OFF}: ${#UNQ_TST[@]} test(s) did not pass\n"
    printf "Failed tests:\n"
    for t in $UNQ_TST; do
        printf "\t${t}\n"
    done
else
    end_time=`date +%s`
    runtime=$((end_time-start_time))
    printf "${C_GREEN}SUCCESS${C_OFF}: $INDEX tests passed (after $runtime s)\n"
fi
