#!/bin/sh

# Write a shell Program to accept a filename from the User and display 
# the attributes,contents and word count of the file .Perform copy,
# rename  operation by accepting two filenames from the user

echo "Enter the file name: \c"
read file_name
cat $file_name
num_words=`cat $file_name|wc -w`
echo "\n number of words : $num_words"
echo "Enter name of another file: \c"
read copy_file
cp $file_name "../"$copy_file
echo "Copy of $file_name created as $new_file in above dir"
echo "Enter name to re-name original file"
read rename
mv $file_name $rename
echo "File renamed from $file_name to $rename"





