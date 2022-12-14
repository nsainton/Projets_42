#!/bin/bash
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
