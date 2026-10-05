#!/bin/bash
echo "Enter num:"
read num
flag=0
for((i=2;i<num;i++))
do 
    if [ $((num%i)) -eq 0 ]
    then
        flag=1
    fi
done
if [ $flag -eq 0 ]
then 
    echo "prime"
else 
    echo "Not Prime"
fi
