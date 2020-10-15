#!/bin/sh

echo "Enter the base"
read base
echo "Enter the exponent"
read exponent
result=$base
if [ $exponent -eq 0 ]
then
echo "Result is 1"
exit 0
fi
while [ $exponent -gt 1 ]
do 
result=`expr $result \* $base`
exponent=`expr $exponent - 1`
done
echo "Result is $result"