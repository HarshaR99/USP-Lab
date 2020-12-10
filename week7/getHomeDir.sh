echo  "Enter user: \c"
read user

homeDir=`grep -v "nologin" /etc/passwd | grep $user | cut -d ":" -f 6`

if [ -z $homeDir ]
then
echo "Invalid username"
else
echo "Home directory of $user is $homeDir"
fi