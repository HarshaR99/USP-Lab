#!/bin/sh

if [ $1 -ge $2 ] && [ $1 -ge $3 ]
then
echo "$1 is greatest."
elif [ $2 -ge $3 ]
then
echo "$2 is greatest"
else
echo "$3 is greatest"
fi
