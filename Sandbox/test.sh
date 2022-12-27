#!/bin/bash

hardware="$(uname -s)"

if [ $hardware == "Darwin" ]
then
	echo Darwin
else
	echo Else
fi

if [ $1 == ""]
then
	echo Empty
else
	echo Something
fi
