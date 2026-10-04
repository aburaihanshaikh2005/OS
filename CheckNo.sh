#Check whether a number is postive,negative or zero.
#!/bin/bash
echo "Enter num:"
read num
if [ $num -gt 0 ]
then 
	echo "Positive ."
elif [ $num -lt 0 ]
then
	echo "Negative no."
else
	echo "Zero"
fi
