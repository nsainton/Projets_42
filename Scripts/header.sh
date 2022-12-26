#!/bin/bash
#Use the script as follows : ./header.sh path/to/project/dir
#The .th file that is created corresponds to a "temporary header"
#extension. This is to ensure that no conflict occurs between
#the files that were previously there and the new file
includes=$1/includes
sources=$1/sources
name=header
ext=th
hardware="$(uname -s)"
file="$includes/$name.$ext"
tmp_file="/tmp/tmp_file"
rm -f $file && echo "" > $file
echo "#ifndef HEADER_H" >> $file
echo "# define HEADER_H" >> $file
for i in $sources/*.c
do
	nb_func="$(egrep '^[a-z]' $i | wc -l)"
	echo "//Functions from $(basename $i) [$nb_func functions]" >> $file
	echo "" >> $file
	if [ $hardware == "Darwin" ]
	then
		egrep '^[a-z]' $i | egrep '^(?:[^s]|s[^t])' \
		| awk 'BEGIN {FS="\n"; RS=""} {for (i = 1; i <= NF; i ++)\
		print $i";\n"}' >> $file
	else
		egrep '^[a-z]' $i |awk 'BEGIN {FS="\n"; RS=""} \
		{for (i = 1; i <= NF; i ++) print $i";\n"}' >> $file
	fi
done
echo -n "#endif" >> $file
#mv $tmp_file $file
