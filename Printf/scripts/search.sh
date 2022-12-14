#!/bin/bash
retour=/tmp/retour
for i in $1/*.c; do echo $(basename $i) >> $retour; cat $i | grep $2 >> $retour; echo "" >> $retour; done && cat $retour && rm -f $retour
