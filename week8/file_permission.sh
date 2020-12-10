#!/bin/sh/

echo "Enter file 1: \c"
read file1
echo "Enter filr 2: \c"
read file2
# permissions for both files
p_1=`ls -l $file1|cut -c 1-10`
p_2=`ls -l $file2|cut -c 1-10`

if [ $p_1 = $p_2 ]
then
echo "Both permissions are same"
echo "The permission is $p_1"
else
echo "permissions are different"
echo "permission for file 1 is $p_1"
echo "permission for file 2 is $p_2"
fi