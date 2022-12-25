#!/bin/bash

hardware="$(uname -s)"

if [ $hardware == "Darwin" ]
then
	echo Darwin
else
	echo Else
fi
