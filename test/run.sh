run()
{
    export _INSTALLER_LG_=yes
    instfile=`mktemp Installer.tmp.XXXXXX`
    echo $1 > $instfile

    which gstat > /dev/null 2>&1
    if [ $? -eq 0 ]; then
        alias stat='gstat'
    fi

    which valgrind > /dev/null 2>&1
    if [ $? -eq 0 ] && [ -z "${LG_SMOKE}" ]; then
        l=`mktemp leak.tmp.XXXXXX`
        o=`valgrind --track-fds=yes --errors-for-leak-kinds=all --leak-check=full --show-leak-kinds=all --track-origins=yes --error-exitcode=1 $prg $instfile 2>$l`
        if [ $? -ne 0 ]; then
            s=`mktemp leak.tmp.XXXXXX`
            cat $l | sed -r 's/==[0-9]+/;==/g' >> $s
            cat $instfile >> $s
            return 2
        fi
        e=`cat $l | grep -v "^==[0-9]\+=="`
        if [ -n "$e" ]; then
            o="$e $o"
        fi
        rm $l
    else
        o=`$prg $instfile 2>&1`
    fi
    rm $instfile
    o=`echo $o | tr -d $nl`
    if [ "$OSTYPE" = "msys" ]; then o=`echo $o | xargs`; fi
    if [ "$o" = "$2" ]; then
        return 1
    else
        l=`mktemp err.tmp.XXXXXX`
        suite=`basename "$4"`
        echo "; $suite:$3" > $l
        echo $1 >> $l
        echo "; Actual result [$o]" >> $l
        echo "; Expected result [$2]" >> $l
        echo "" >> $l
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
        eval "$pre"
        if [ $? -ne 0 ]; then
            echo "In line $3 ERR:$pre"
            return 0
        fi
    fi
    run "$1 ; [$pre ; $pst]" "$inf" "$3" "$4"
    ret=$?
    if [ -n "$pst" ]; then
        eval "$pst"
        if [ $? -ne 0 ]; then
            echo "In line $3 FAIL/ERR:$pst"
            if [ $ret -eq 1 ]; then
                ret=0
            fi
        fi
    fi
    which valgrind > /dev/null 2>&1
    if [ $? -eq 0 ]  && [ -z "${LG_SMOKE}" ] && [ -z "${LG_QUICK}" ] && [ -z "${LG_FAIL}" ]; then
        if [ -n "$pre" ]; then
            eval "$pre" 2>&1
        fi
        instfile=`mktemp Installer.tmp.XXXXXX`
        massfile=`mktemp massif.out.XXXXXX`
        echo "$1 ; [$pre ; $pst]" > $instfile
        valgrind --tool=massif --massif-out-file=$massfile --stacks=yes $prg $instfile > /dev/null 2>&1
        snip=$(echo $1 | tr -d '.' | tr '/' '_' | tr -d '"' | tr -d $nl)
        sed -i "s/mem_stacks_B=/$snip mem_stacks_B=/g" $massfile
        sed -i "s/mem_heap_B=/$snip mem_heap_B=/g" $massfile
        if [ -n "$pst" ]; then
            eval "$pst" 2>&1
        fi
    fi
    return $ret
}

prg=$1
tst=$2
nfl=0
nok=0

nl='\n';
if [ $OSTYPE"" = "msys" ]; then nl='\r'; fi

for f in `ls -t $tst/test.*`;
do
    tno=0
    echo "-> $f"
    while read -r l;
    do
       p=`echo "$l" | sed -e 's/;.*$//'`
       r=`echo "$l" | sed -e 's/.*;//'`
       if [ ! -z "$p" ]; then
           tno=$(( $tno + 1 ))
           evl "$p" "$r" "$tno" "$f"
           s=$?
           p=$(echo $p | tr $nl ' ')
           if [ $s -eq 2 ]; then
               echo "LEAK -> $p"
               nok=$(( $nok + 1 ))
               exit 1
           elif [ $s -eq 1 ]; then
               echo "OK -> $p" 
               nok=$(( $nok + 1 ))
           elif [ $s -eq 0 ]; then
               if [ ! -z "${LG_FAIL}" ]; then
                   echo "IGNORE -> $p"
                   nok=$(( $nok + 1 ))
               else
                   echo "FAIL -> $p"
                   nfl=$(( $nfl + 1 ))
               fi
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

which valgrind > /dev/null 2>&1
if [ $? -eq 0 ]  && [ -z "${LG_SMOKE}" ] && [ -z "${LG_QUICK}" ] && [ -z "${LG_FAIL}" ]; then
    echo Peak stack in $(grep -h mem_stacks_B massif.out.* | sort -h -k 2 -t '=' | tail -1 | sed -e 's/mem_stacks_B=//') bytes
    echo Peak heap in $(grep -h mem_heap_B massif.out.* | sort -h -k 2 -t '=' | tail -1 | sed -e 's/mem_heap_B=//') bytes
    rm -f massif.out.*
fi

exit $nfl
