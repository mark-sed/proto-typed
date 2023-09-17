if [ -n "$1" ]; then
    PROG=$(echo "$1" | cut -f 1 -d '.')
else
    echo "First argument has to be path to the .pt file"
    exit 1
fi

if [ -n "$2" ]; then
    VERBOSE=$2
else
    VERBOSE=0
fi

./build/ptc/ptc ${PROG}.pt -verbose ${VERBOSE} -filetype=obj -relocation-model=pic && gcc ${PROG}.o ptlib.o -o ${PROG}.out && rm ${PROG}.o && ./${PROG}.out
