#!/bin/bash
if [ $# -ne 2 ]
then
    echo "Usage: fail_this file line"
    exit 1
fi
numb=$(grep DBG_ALLOC ../src/*.c -n | wc -l)
file=$(grep DBG_ALLOC ../src/*.c -n | awk -F: '{print $1}')
line=$(grep DBG_ALLOC ../src/*.c -n | awk -F: '{print $2}')
numb=$(awk -v min=1 -v max="$numb" 'BEGIN{srand(); print int(min+rand()*(max-min+1))}')
file=$1
line=$2
echo "---------------------------------------------------------------------"
echo "Memory allocation fault injection in $file line $line"
echo "---------------------------------------------------------------------"
make clean
make CFLAGS="-I . -I ../src -g -std=c99 -D_DEFAULT_SOURCE -D_GNU_SOURCE -DFAIL_LINE=$line -DFAIL_FILE='\"$file\"'"
make fail
ls leak.tmp.* &> /dev/null && cat leak.tmp.* && exit 1
ls err.tmp.* &> /dev/null && echo $(ls -l err.tmp.* 2> /dev/null | wc -l) "error(s) handled without leaks." && exit 0
echo "No errors and no leaks."
exit 0
