#!bin/sh

echo "Enter a number: \c"
read n
if [ $n -eq 0 ] || [ $n -eq 1 ]
then
echo "Result is 0"
exit 0
fi

i=1
sum=0
rem=0
while [ $i -le $n ]
do
rem=`expr $i % 2`
if [ $rem -eq 0 ]
then
sum=`expr $sum + $i`
fi 
i=`expr $i + 1`
done

echo "Result is $sum"
