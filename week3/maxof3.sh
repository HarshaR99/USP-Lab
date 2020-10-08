#!/bin/sh

if [ $1 -ge $2 ] && [ $1 -ge $3 ]
then
echo "$1 is greatest."
elif [ $2 -ge $3 ]
then
echo "$2 is greatest"
elif test $2 -eq $3
then 
echo "All are equal"
else
echo "$3 is greatest"
fi
