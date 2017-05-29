exe()
{
    return 0
}

out()
{
    o=`echo $1 | $prg 2>&1 | head -n 1` 
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
for f in $tst/test.*; 
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
