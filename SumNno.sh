#Sum of n natural number.
#!/bin/bash
echo "Enter Num:"
read num
Sum=0
for((i=1;i<=num;i++))
do
  Sum=$((Sum+i))
done
  echo "Sum of n natural no=$Sum"
  
  


