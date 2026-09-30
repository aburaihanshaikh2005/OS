#!/bin/bash
#Greatest of Three No
echo "Enter num1:"
read n1
echo "Enter num2:"
read n2
echo "Enter num3:"
read n3
if [ $n1 -gt $n2 ] && [ $n1 -gt $n3 ] 
then 
   echo "$n1 is greater"
elif [ $n2 -gt $n1 ] && [ $n2 -gt $n3 ] 
then
   echo "$n2 is greater"
else 
   echo "$n3 is greater"
fi
