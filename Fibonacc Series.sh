#Fibonacci Series
#!/bin/bash
echo "Enter n:"
read n
a=0
b=1
count=2
echo "Fibonacci Series: $a $b"
while ((count<n))
do	
	temp=$b
	b=$((a+b))
	a=$temp
	((count++))
	echo -n "$b "
done

