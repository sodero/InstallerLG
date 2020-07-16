#!/bin/bash
if [ $# -ne 4 ]
then
    echo "Usage: fail_this file_alloc line_alloc file_fopen line_fopen"
    exit 1
fi

alloc_file=$1
alloc_line=$2
fopen_file=$3
fopen_line=$4

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
