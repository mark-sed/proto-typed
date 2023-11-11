if [ -n "$1" ]; then
    PROG=$(echo "$1" | cut -f 1 -d '.')
    shift
else
    echo "First argument has to be path to the .pt file"
    exit 1
fi

if [ -n "$1" ]; then
    VERBOSE=$1
    shift
else
    VERBOSE=0
fi

if [ -n "$1" ]; then
    DIR=$1
    shift
else
    DIR=./
fi

GC="gc"
LPATH=$DIR"gc/"

$DIR"build/ptc/ptc" ${PROG}.pt -verbose ${VERBOSE} -filetype=obj -relocation-model=pic && gcc -L${LPATH} ${PROG}.o $DIR"ptlib.o" $@ -o ${DIR}${PROG}.out -lm -l${GC} && rm ${PROG}.o && ${DIR}${PROG}.out
