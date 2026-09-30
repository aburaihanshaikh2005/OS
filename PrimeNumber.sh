#!/bin/bash
# Prime Number
echo "Enter Number:"
read num
found=0
for ((i=2; i<num; i++))
do
    if (( num % i == 0 )); then
        found=1
        break
    fi
done
if (( num <= 1 )); then
    echo "Non Prime"
elif (( found == 0 )); then
    echo "Prime Number"
else
    echo "Non Prime"
fi

