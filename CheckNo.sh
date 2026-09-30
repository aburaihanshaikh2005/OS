#Check whether a number is postive,negative or zero.
#!/bin/bash
echo "Enter Number:"
read num

if [ $num -gt 0 ]; then
  echo "$num is positive number"
elif [ $num -lt 0 ]; then
  echo "$num is negative number"
else 
  echo "$num is zero."
fi
