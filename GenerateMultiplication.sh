# Generate Multiplication Table
#!/bin/bash
echo "Enter the no you want to generate multiplication table="
read n
for ((i=1;i<=10;i++))
do
  echo "$n X $i=$((n*i))"
done
