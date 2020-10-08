#!/bin/sh

# using cmd line arguments to find given pattern in a file

if test $# -eq 0
then
echo "Usage $0 pattern file"
elif test $# -eq 2
then
grep "$1" $2||echo "Pattern $1 not foind in $2"
else
echo "Enter two arguements"
fi 
