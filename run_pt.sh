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

if [ -n "$3" ]; then
    DIR=$3
else
    DIR=./
fi

$DIR"build/ptc/ptc" ${PROG}.pt -verbose ${VERBOSE} -filetype=obj -relocation-model=pic && gcc ${PROG}.o $DIR"ptlib.o" -o ${DIR}${PROG}.out -lm && rm ${PROG}.o && ${DIR}${PROG}.out
