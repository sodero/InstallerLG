#!/bin/bash
if [ $# -ne 10 ]
then
    echo "Usage: fail_this file_alloc line_alloc file_fopen line_fopen file_dopen line_dopen file_zero line_zero file_addr line_addr"
    exit 1
fi

alloc_file=$1
alloc_line=$2
shift 2
fopen_file=$1
fopen_line=$2
shift 2
dopen_file=$1
dopen_line=$2
shift 2
zero_file=$1
zero_line=$2
shift 2
addr_file=$1
addr_line=$2
shift 2

echo "---------------------------------------------------------------------"
echo "Fault injection"
echo "---------------------------------------------------------------------"
echo "MALLOC $alloc_file:$alloc_line"
echo "FOPEN $fopen_file:$fopen_line"
echo "DOPEN $dopen_file:$dopen_line"
echo "ZERO $zero_file:$zero_line"
echo "ADDR $addr_file:$addr_line"
echo "---------------------------------------------------------------------"
make clean
make CFLAGS="-I . -I ../src -g -std=c99 -D_DEFAULT_SOURCE -D_GNU_SOURCE -D__AMIGADATE__='\"23.07.1985\"' -DFAIL_LINE_ALLOC=$alloc_line -DFAIL_FILE_ALLOC='\"$alloc_file\"' -DFAIL_LINE_FOPEN=$fopen_line -DFAIL_FILE_FOPEN='\"$fopen_file\"' -DFAIL_LINE_DOPEN=$dopen_line -DFAIL_FILE_DOPEN='\"$dopen_file\"' -DFAIL_LINE_ZERO=$zero_line -DFAIL_FILE_ZERO='\"$zero_file\"' -DFAIL_LINE_ADDR=$addr_line -DFAIL_FILE_ADDR='\"$addr_file\"'"
test -e ./Installer && make fail || exit 1
ls leak.tmp.* &> /dev/null && cat leak.tmp.* && exit 1
ls err.tmp.* &> /dev/null && echo $(ls -l err.tmp.* 2> /dev/null | wc -l) "error(s) handled without leaks." && exit 0
echo "No errors and no leaks."
exit 0
