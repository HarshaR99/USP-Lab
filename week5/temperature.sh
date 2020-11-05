#!/bin/sh

celcius=`echo  "($1-35)*5/9"|bc`
echo $celcius