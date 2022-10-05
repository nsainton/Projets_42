#!/bin/zsh
cpp main_test.c
gcc -Wall -Wextra -Werror main_test.c
./a.out
rm a.out
