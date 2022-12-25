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
for i in $sources/*.c
do
	echo "//Functions from $(basename $i) " >> $file
	echo "" >> $file
	egrep '^[a-z]' $i | egrep '^(?:[^s]|s[^t])' \
	| awk 'BEGIN {FS="\n"; RS=""} {for (i = 1; i <= NF; i ++)\
	print $i";\n\n"}' >> $file
	echo "" >> $file
done
if [ $hardware == "Darwin" ]
then
column -s $'\t' -t $file > $tmp_file
else
column -s $'\t' -t -L -o $'\t' $file > $tmp_file
fi
mv $tmp_file $file
