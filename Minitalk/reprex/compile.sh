#!/bin/bash
gcc -Wall -Wextra -Werror client.c -o client && gcc -Wall -Wextra -Werror server.c -o server && ./server
