#Use the script like : ./Script test_file.c
o_file="$(basename $1 .c)"
if [ "$1" == "" ]
then
	echo Script is meant to be used by running ./tmpget.sh test_file.c
	exit 2
fi
../../Scripts/getlib.sh ../../Libft libft.a && gcc -Wall -Wextra\
 -Werror -g3 $1 libft.a -o $o_file 
