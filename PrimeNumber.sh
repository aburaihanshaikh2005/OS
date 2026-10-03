#!/bin/bash
# Prime Number
echo "Enter num:"
read num
flag=0
for ((i=2;i<num;i++))
do
	if [ $((num%i)) -eq 0 ]
	then 
		flag=1
	fi
done
if [ $flag -eq 0 ]
then
	echo "Prime Number"
else
	echo "Not a Prime Number"
fi

	

