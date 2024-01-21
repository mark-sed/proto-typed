#!/bin/bash

PTC_LIB_PATH="/lib/ptc"
STD_PATH=${PTC_LIB_PATH}"/std"
GC_PATH=${PTC_LIB_PATH}"/gc"

mkdir -p ${PTC_LIB_PATH}
mkdir -p ${STD_PATH}

rm -f ${STD_PATH}/libptl.o ${STD_PATH}/libpt.pt
rm -rf ${GC_PATH}

cp -r gc $GC_PATH
cp ptc/libptl.o ${STD_PATH}/libptl.o
cp ptc/libpt.pt ${STD_PATH}/libpt.pt

rm -f /bin/ptc
chmod +x build/ptc/ptc
cp build/ptc/ptc /bin/ptc
cp build/pt /bin/pt