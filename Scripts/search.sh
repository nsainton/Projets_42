#!/bin/bash
# Call the script as follows : ./search.sh path/to/dir func_to_search_for
retour=/tmp/retour
func=$2
for i in $1/*.c
do
	echo $(basename $i) >> $retour
	egrep '^[^/]' $i | grep $func >> $retour
	echo "" >> $retour
done
cat $retour
rm -f $retour
