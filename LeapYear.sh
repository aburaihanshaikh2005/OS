#!/bin/bash
#Leap Year
echo "Enter a Year:"
read n
if (( n % 400 == 0 )) || (( n % 4 == 0 && n % 100 != 0 ))
then
    echo "This is a Leap year"
else
    echo "This is not a Leap year"
fi

