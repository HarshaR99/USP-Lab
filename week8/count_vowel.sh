#!/bin/sh

echo "Enter filename: \c"
read file
count=`tr -cd "[aeiouAEIOU]"<$file|wc -c`
echo "Number of vowels in file are $count"