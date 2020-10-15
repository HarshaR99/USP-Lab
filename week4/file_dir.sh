#!/bin/sh

if test $# -ne 1
then
echo "Please enter file or directory name"
exit 1
fi

if [ -d $1 ]
then
echo "$1 is a directory"
ls -ld $1
elif [ -f $1 ]
then 
echo "$1 is a file"
ls -la $1 
else
echo "Wrong path"
fi
