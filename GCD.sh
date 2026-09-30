#!/bin/bash
echo "Enter num1:"                  
read a
echo "Enter num2:"
read b
num1=$a
num2=$b
while [ $b -ne 0 ]
do 
  temp=$b
  b=$((a%b))
  a=$temp
done
echo "GCD of $num1 and $num2 is: $a "
