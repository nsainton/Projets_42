#!/bin/bash
includes=$1/includes
sources=$1/sources
name=header
ext=th
file="$includes/$name.$ext"
rm -f $file; touch $file
for i in $sources/*.c
do
	echo "//Functions from $(basename $i) " >> $file
	egrep '^([a-z])+' $i | awk 'BEGIN {FS="\n"; RS=""} {for (i = 1; i <= NF; i ++)\
	print $i";\n"}' >> ${file}
	echo "" >> $file
done
