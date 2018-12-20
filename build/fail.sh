#!/bin/bash

numb=$(grep DBG_ALLOC ../src/*.c -n | wc -l)
file=$(grep DBG_ALLOC ../src/*.c -n | awk -F: '{print $1}')
line=$(grep DBG_ALLOC ../src/*.c -n | awk -F: '{print $2}')
numb=$(awk -v min=1 -v max="$numb" 'BEGIN{srand(); print int(min+rand()*(max-min+1))}')
file=$(echo "$file" | head -n $numb | tail -n 1)
line=$(echo "$line" | head -n $numb | tail -n 1)
echo "---------------------------------------------------------------------"
echo "Memory allocation fault injection in $file line $line"
echo "---------------------------------------------------------------------"
make clean &> /dev/null
make CFLAGS="-I . -I ../src -g -std=c99 -D_DEFAULT_SOURCE -DFAIL_GTE=$line -DFAIL_FILE='\"$file\"'" &> /dev/null
make test | grep '^->'
ls leak.tmp.* &> /dev/null && cat leak.tmp.* && exit 1
ls err.tmp.* &> /dev/null && echo $(ls -l err.tmp.* 2> /dev/null | wc -l) "error(s) handled without leaks." && exit 0
echo "No errors and no leaks."
exit 0
