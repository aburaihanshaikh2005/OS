#Fibonacci Series
#!/bin/bash
echo "Enter n:"
read n
a=0
b=1
count=2
echo -n "Fibonacci Series 0 1 "
while((count<n))
do 
  temp=$b
  b=$((a+b))
  a=$temp
  ((count++))
  echo -n "$b "
done


