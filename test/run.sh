run()
{
    instfile=`mktemp ./installer.tmp.XXXXXX`
    echo $1 > $instfile
    if [ `uname` = "Linux" ]; then
        o=`valgrind --errors-for-leak-kinds=all --leak-check=full --show-leak-kinds=all --track-origins=yes --error-exitcode=1 $prg $instfile 2>&1`
        if [ $? -ne 0 ]; then
            l=`mktemp ./leak.tmp.XXXXXX`
            cp $instfile $l
            echo $o | sed -r 's/==[0-9]+/\n;==/g' >> $l
            cat $l
        fi
    fi
    o=`$prg $instfile 2>&1 | head -n 1` 
    rm $instfile 
    if [ "$o" = "$2" ]; then
        return 1
    else
        echo "Actual result [$o]"
        echo "Expected result [$2]"
        return 0
    fi
}

evl()
{
    ret=1
    pre=`echo "$2" | sed -e 's/.*\"\(.*\)\",\".*\",\".*\".*$/\1/'`
    inf=`echo "$2" | sed -e 's/.*\".*\",\"\(.*\)\",\".*\".*$/\1/'`
    pst=`echo "$2" | sed -e 's/.*\".*\",\".*\",\"\(.*\)\".*$/\1/'`
    if [ -n "$pre" ]; then 
        o=`eval "$pre" 2>&1`
        if [ $? -ne 0 ]; then
            echo "ERR:$o"
            return 0
        fi
    fi
    run "$1 ; [$pre ; $pst]" "$inf" 
    if [ $? -eq 0 ]; then
        ret=0
    fi
    if [ -n "$pst" ]; then 
        o=`eval "$pst" 2>&1`
        if [ $? -ne 0 ]; then
            echo "FAIL/ERR:$o"
            ret=0
        fi
    fi
    return $ret 
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

