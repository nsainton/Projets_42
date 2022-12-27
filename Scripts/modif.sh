#!/bin/bash

tmp="/tmp/tmp_file"
path=$1
Libpath="../Libft"
if [ "$1" = "" ]
then
	echo Must provide one argument for the script to work properly
	exit 3
fi
echo $1
make -C $Libpath
gcc -Wall -Wextra -Werror $Libpath/libft.a modif.c -o modif
for i in $path/*
do
	./modif $i $tmp
	mv $tmp $i
	chmod 644 $i
done
make fclean -C $Libpath
rm modif
