#!/bin/bash
#Use the script as follows : ./header.sh path/to/project/dir
includes=$1/includes
sources=$1/sources
name=header
ext=th
file="$includes/$name.$ext"
tmp_file="/tmp/tmp_file"
rm -f $file; touch $file
for i in $sources/*.c
do
	echo "//Functions from $(basename $i) " >> $file
	echo "" >> $file
	egrep '^([a-z])+' $i | awk 'BEGIN {FS="\n"; RS=""} {for (i = 1; i <= NF; i ++)\
	print $i";\n\n"}' >> $file
	echo "" >> $file
done
rm -f $tmp_file
