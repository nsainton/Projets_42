make -s re -C ..
gcc -Wall -Wextra -Werror test_printf.c ../libftprintf.a -o test_printf
gcc -Wall -Wextra -Werror test_ftprintf.c ../libftprintf.a -o test_ftprintf
./test_printf > test_printf.txt
./test_ftprintf > test_ftprintf.txt
diff test_printf.txt test_ftprintf.txt
rm -f test_printf test_ftprintf test_printf.txt test_ftprintf.txt
