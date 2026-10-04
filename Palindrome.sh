#Palindrome Number
#!/bin/bash
echo "Enter number:"
read num
result=$num
rev=0
while ((num!=0))
do
	temp=$((num%10))
	rev=$((rev*10+temp))
	num=$((num/10))
done
if [ $result -eq $rev ]
then
	echo "Palindrome"
else 
	echo "Not Palindrome"
fi
