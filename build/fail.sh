#!/bin/bash

alloc_numb=$(grep DBG_ALLOC ../src/*.c -n | wc -l)
alloc_file=$(grep DBG_ALLOC ../src/*.c -n | awk -F: '{print $1}')
alloc_line=$(grep DBG_ALLOC ../src/*.c -n | awk -F: '{print $2}')
alloc_numb=$(awk -v min=1 -v max="$alloc_numb" 'BEGIN{srand(); print int(min+rand()*(max-min+1))}')
alloc_file=$(echo "$alloc_file" | head -n $alloc_numb | tail -n 1)
alloc_line=$(echo "$alloc_line" | head -n $alloc_numb | tail -n 1)
fopen_numb=$(grep DBG_FOPEN ../src/*.c -n | wc -l)
fopen_file=$(grep DBG_FOPEN ../src/*.c -n | awk -F: '{print $1}')
fopen_line=$(grep DBG_FOPEN ../src/*.c -n | awk -F: '{print $2}')
fopen_numb=$(awk -v min=1 -v max="$fopen_numb" 'BEGIN{srand(); print int(min+rand()*(max-min+1))}')
fopen_file=$(echo "$fopen_file" | head -n $fopen_numb | tail -n 1)
fopen_line=$(echo "$fopen_line" | head -n $fopen_numb | tail -n 1)

echo "---------------------------------------------------------------------"
echo "MALLOC fault injection in $alloc_file line $alloc_line"
echo "FOPEN file fault injection in $fopen_file line $fopen_line"
echo "---------------------------------------------------------------------"
make clean
make CFLAGS="-I . -I ../src -g -std=c99 -D_DEFAULT_SOURCE -D_GNU_SOURCE -D__AMIGADATE__='\"23.07.1985\"' -DFAIL_LINE_ALLOC=$alloc_line -DFAIL_FILE_ALLOC='\"$alloc_file\"' -DFAIL_LINE_FOPEN=$fopen_line -DFAIL_FILE_FOPEN='\"$fopen_file\"'"
test -e ./Installer && make fail || exit 1
ls leak.tmp.* &> /dev/null && cat leak.tmp.* && exit 1
ls err.tmp.* &> /dev/null && echo $(ls -l err.tmp.* 2> /dev/null | wc -l) "error(s) handled without leaks." && exit 0
echo "No errors and no leaks."
exit 0
