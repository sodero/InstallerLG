run()
{
    instfile=`mktemp ./installer.tmp.XXXXXX`
    echo $1 > $instfile
    if [ `uname` = "Linux" ]; then
        #valgrind -q --errors-for-leak-kinds=all --leak-check=full --show-leak-kinds=all --error-exitcode=1 $prg $instfile > /dev/null 2>&1
        valgrind -q --error-exitcode=1 $prg $instfile > /dev/null 2>&1
        if [ $? = 1 ]; then
            valgrind --leak-check=full --show-leak-kinds=all --track-fds=yes --track-origins=yes $prg $instfile 
            cp $instfile `mktemp ./leak.tmp.XXXXXX`
        fi
    fi
    o=`$prg $instfile 2>&1 | head -n 1` 
    rm $instfile 
    if [ "$o" = "$2" ]; then
        return 1
    else
        echo "Actual result: $o"
        echo "Expected result: $2"
        return 0
    fi
}

evl()
{
    cur=`echo "$2" | sed -e 's/.*\"\(.*\)\",\".*\",\".*\".*$/\1/'`
    if [ -n "$cur" ]; then 
        o=`eval "$cur" 2>&1`
        if [ $? -ne 0 ]; then
            echo "ERR:$o"
            return 0
        fi
    fi
    cur=`echo "$2" | sed -e 's/.*\".*\",\"\(.*\)\",\".*\".*$/\1/'`
    if [ -n "$cur" ]; then 
        run "$1" "$cur" 
        if [ $? -eq 0 ]; then
            return 0
        fi
    fi
    cur=`echo "$2" | sed -e 's/.*\".*\",\".*\",\"\(.*\)\".*$/\1/'`
    if [ -n "$cur" ]; then 
        o=`eval "$cur" 2>&1`
        if [ $? -ne 0 ]; then
            echo "FAIL/ERR:$o"
            return 0
        fi
    fi
    return 1 
}

prg=$1
tst=$2
nfl=0
nok=0
for f in `ls -t $tst/test.*`; 
do 
    echo "-> $f"
    while read -r l; 
    do
       p=`echo "$l" | sed -e 's/;.*$//'`
       r=`echo "$l" | sed -e 's/.*;//'`
       if [ ! -z "$p" ]; then 
           evl "$p" "$r" 
           if [ $? = 1 ]; then
               echo "OK -> $p" 
               nok=$(( $nok + 1 ))
           else 
               echo "FAIL -> $p"
               nfl=$(( $nfl + 1 ))
           fi
       fi
    done < $f
done
tot=$(( $nok + $nfl ))
echo "--------------------------------------------"
if [ $nfl -eq 0 ]; then
    echo "All $tot test(s) passed"
else
    echo "$nfl test(s) failed"
    echo "$nok test(s) passed"
fi
echo "--------------------------------------------"

