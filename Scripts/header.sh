#!/bin/bash
#Use the script as follows : ./header.sh path/to/project/dir
#The .th file that is created corresponds to a "temporary header"
#extension. This is to ensure that no conflict occurs between
#the files that were previously there and the new file
includes=$1/includes
sources=$1/sources
name=header
ext=th
final_name=functions
final_ext=h
hardware="$(uname -s)"
file="$includes/$name.$ext"
final_file="$includes/$final_name.$final_ext"
tmp_file="/tmp/tmp_file"
rm -f $file && echo "" > $file
echo "#ifndef FUNCTIONS_H" >> $file
echo "# define FUNCTIONS_H" >> $file
echo "# include \"librairies.h\"" >> $file
echo "# include \"structures.h\"" >> $file
echo "# include \"enums.h\"" >> $file
echo "# include \"typedefs.h\"" >> $file
echo "" >> $file
for i in $sources/*.c
do
	nb_func="$(egrep '^[a-z\s_ ]+\t+' $i | wc -l)"
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
mv $file $final_file
