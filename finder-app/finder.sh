#!/bin/sh
if [ $# -ne 2 ];
then 
    echo "paremeters are not specified"
    exit 1
fi
if [ ! -d $1 ];
then
    echo "$1 does not represent a directory in a filesystem"
    exit 1
fi
echo "$1"
var1=$( find $1 -type f | wc -l )
var2=$( find $1 -type f | xargs cat | grep $2 | wc -l)
echo "The number of files are $var1 and the number of matching lines are $var2"


