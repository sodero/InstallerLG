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

dopen_numb=$(grep DBG_DOPEN ../src/*.c -n | wc -l)
dopen_file=$(grep DBG_DOPEN ../src/*.c -n | awk -F: '{print $1}')
dopen_line=$(grep DBG_DOPEN ../src/*.c -n | awk -F: '{print $2}')
dopen_numb=$(awk -v min=1 -v max="$dopen_numb" 'BEGIN{srand(); print int(min+rand()*(max-min+1))}')
dopen_file=$(echo "$dopen_file" | head -n $dopen_numb | tail -n 1)
dopen_line=$(echo "$dopen_line" | head -n $dopen_numb | tail -n 1)

zero_numb=$(grep DBG_ZERO ../src/*.c -n | wc -l)
zero_file=$(grep DBG_ZERO ../src/*.c -n | awk -F: '{print $1}')
zero_line=$(grep DBG_ZERO ../src/*.c -n | awk -F: '{print $2}')
zero_numb=$(awk -v min=1 -v max="$zero_numb" 'BEGIN{srand(); print int(min+rand()*(max-min+1))}')
zero_file=$(echo "$zero_file" | head -n $zero_numb | tail -n 1)
zero_line=$(echo "$zero_line" | head -n $zero_numb | tail -n 1)

addr_numb=$(grep DBG_ADDR ../src/*.c -n | wc -l)
addr_file=$(grep DBG_ADDR ../src/*.c -n | awk -F: '{print $1}')
addr_line=$(grep DBG_ADDR ../src/*.c -n | awk -F: '{print $2}')
addr_numb=$(awk -v min=1 -v max="$addr_numb" 'BEGIN{srand(); print int(min+rand()*(max-min+1))}')
addr_file=$(echo "$addr_file" | head -n $addr_numb | tail -n 1)
addr_line=$(echo "$addr_line" | head -n $addr_numb | tail -n 1)

echo "---------------------------------------------------------------------"
echo "MALLOC fault injection in $alloc_file line $alloc_line"
echo "FOPEN file fault injection in $fopen_file line $fopen_line"
echo "DOPEN file fault injection in $dopen_file line $dopen_line"
echo "ZERO file fault injection in $zero_file line $zero_line"
echo "ADDR file fault injection in $addr_file line $addr_line"
echo "---------------------------------------------------------------------"
make clean
make CFLAGS="-I . -I ../src -g -std=c99 -D_DEFAULT_SOURCE -D_GNU_SOURCE -D__AMIGADATE__='\"23.07.1985\"' -DFAIL_LINE_ALLOC=$alloc_line -DFAIL_FILE_ALLOC='\"$alloc_file\"' -DFAIL_LINE_FOPEN=$fopen_line -DFAIL_FILE_FOPEN='\"$fopen_file\"' -DFAIL_LINE_DOPEN=$dopen_line -DFAIL_FILE_DOPEN='\"$dopen_file\"' -DFAIL_LINE_ZERO=$zero_line -DFAIL_FILE_ZERO='\"$zero_file\"' -DFAIL_LINE_ADDR=$addr_line -DFAIL_FILE_ADDR='\"$addr_file\"'"
test -e ./Installer && make fail || exit 1
ls leak.tmp.* &> /dev/null && cat leak.tmp.* && exit 1
ls err.tmp.* &> /dev/null && echo $(ls -l err.tmp.* 2> /dev/null | wc -l) "error(s) handled without leaks." && exit 0
echo "No errors and no leaks."
exit 0
