exe()
{
    return 0
}

out()
{
    instfile=`mktemp ./installer.tmp.XXXXXX`
    echo $1 > $instfile
    if [ `uname` = "Linux" ]; then
        valgrind -q --leak-check=full --error-exitcode=1 $prg $instfile > /dev/null 2>&1
        if [ $? = 1 ]; then
            valgrind --leak-check=full --show-reachable=yes --track-fds=yes --track-origins=yes $prg $instfile 
            mv $instfile `mktemp ./leak.tmp.XXXXXX`
            return 0
        fi
    fi
    o=`$prg $instfile 2>&1 | head -n 1` 
    rm $instfile 
    if [ "$o" = "$2" ]; then
        return 1
    else
        echo "Got: $o"
        echo "Exp: $2"
        return 0
    fi
}

evl()
{
    t=`echo "$2" | sed -e 's/=.*$//'`
    w=`echo "$2" | sed -e 's/.*=\"\(.*\)\".*/\1/'`
    if [ $t = "out" ]; then 
        out "$1" "$w" 
        return $?
    elif [ $t = "exe" ]; then
        exe "$1" "$w"
        return $?
    else
        return 0
    fi
}

prg=$1
tst=$2
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
           else 
               echo "FAIL -> $p"
           fi
       fi
    done < $f
done
