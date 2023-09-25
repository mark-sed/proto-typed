#!/usr/bin/env bash

# Script for running proto-typed tests and checking the results

function print_help {
    printf "Proto-typed test suite.\nUsage: bash $0\n" 
}

PTC="ptc"
PT="../run_pt.sh"
OUTP_ERR=/tmp/.ptc_test_err.txt
OUTP_STD=/tmp/.ptc_test_std.txt
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
    printf "${C_RED}FAILED${C_OFF}: $1\n"
    
}

function run {
    CMD="$PT $1 0 $WRKDIR"
    $CMD 2>$OUTP_ERR 1>$OUTP_STD
    RETCODE=$(echo $?)
    # Get output binary name
    PROGNAME=$(echo "$1" | cut -f 1 -d '.')".out"
    rm -f ${WRKDIR}${PROGNAME}
}

function except_pass {
    run $1
    if [[ $RETCODE -ne 0 ]]; then
        failed $2
        printf "Command:\n--------\n$CMD\n"
        printf "Output:\n-------\n"
        cat $OUTP_STD
        printf "Error output:\n-------------\n"
        cat $OUTP_ERR
    fi
}

function expect_out_eq {
    outstr=$(cat $OUTP_STD)
    if [[ "$outstr" != "$1" ]]; then
        failed $2
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
    except_pass "fib.pt" "fib"
    expect_out_eq "55" "fib"
}

function run_all_tests {
    run_test fib
}

# Count all functions starting with test_ 
TEST_AMOUNT=$(declare -F | grep "test_" | wc -l)
run_all_tests
