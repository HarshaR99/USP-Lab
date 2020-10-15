#!/bin/sh
if test $# -ne 1
then
echo "Parameter not passed"
exit 1
fi

factorial=1
echo "Factorial of $1 = "
if [ $1 -eq 1 ] || [ $1 -eq 0 ]
then
echo $factorial
exit 0
fi

number=$1

while [ $number -gt 1 ]
do
factorial=`expr $factorial \* $number`
number=`expr $number - 1`
done

echo $factorial
