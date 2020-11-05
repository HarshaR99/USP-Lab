#!/bin/sh

echo "Enter first number: \c"
read a
echo "Enter first number: \c"
read b
echo "Enter operator: \c" 
read operator

echo "Result is :\c "

case $operator in
+)echo "`expr $a + $b`"
;;
-)echo "`expr $a - $b`"
;;
\*)echo "`expr $a \* $b`"
;;
/)echo "`expr $a / $b`"
;;
*)echo "Invalid operator"
;;
esac