#!/bin/sh


if test $1 -lt 0
then
	echo "No fibonacci numbers"
exit 1
fi


if [ $1 -le 2 ]
then
n=0
while [ $n -lt $1 ]
do
	echo $n
	n=`expr $n + 1`
done
exit 0
fi

a=0
b=1
c=`expr $a + $b`
n=`expr $1 - 2`
echo $a
echo $b
while [ $n -ne 0 ]
do
	echo $c
	a=$b
	b=$c
	c=`expr $a + $b`
	n=`expr $n - 1`
done
