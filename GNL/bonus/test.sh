echo "Bienvenue dans le programme de test de la version bonus de GNL"
gcc -Wall -Wextra -Werror *.c -D BUFF_SIZE=5 && ./a.out "Bonjour" "test.c" "get_next_line.c" "get_next_line_utils.c" "get_next_line.h"
rm a.out 2>/dev/null
echo "Merci d'avoir testé ma fonction GNL. Bonne journée"
