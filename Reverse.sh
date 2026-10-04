#Reverse of number
#!/bin/bash
echo "Enter Number:"
read num
rev=0
while [ $num -ne 0 ]
do 
  temp=$((num%10))
  rev=$((rev*10+temp))
  num=$((num/10))
done
echo "Reverse Number:$rev"
