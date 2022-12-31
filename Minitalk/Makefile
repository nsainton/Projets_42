# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/31 22:53:20 by nsainton          #+#    #+#              #
#    Updated: 2022/12/31 23:55:35 by nsainton         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= Minitalk

CLIENT= client

SERVER= server

SOURCES= debug.c

INCLUDES= includes

LIBFT_DIR= ../Libft

LIBFT_NAME= libft.a

LIBFT= $(addprefix $(LIBFT_DIR)/, $(LIBFT_NAME))

CC= gcc

CFLAGS= -Wall -Wextra -Werror

all:
	$(MAKE) $(NAME)

$(NAME):
	$(MAKE) $(SERVER)
	$(MAKE) $(CLIENT)

$(SERVER): $(SERVER).c $(SOURCES) $(LIBFT)
	$(CC) $(CFLAGS) $(OPT) $(GG) $(SERVER).c $(SOURCES) $(LIBFT) -o $(SERVER) -I $(INCLUDES)

$(CLIENT): $(CLIENT).c $(SOURCES) $(LIBFT)
	$(CC) $(CFLAGS) $(OPT) $(GG) $(CLIENT).c $(SOURCES) $(LIBFT) -o $(CLIENT) -I $(INCLUDES)

%.o: %.c $(wildcard $(INCLUDES)/*) $(LIBFT)
	$(CC) $(CFLAGS) $(OPT) $(GG) -c $< -o $@ -I $(INCLUDES)

$(LIBFT): | $(LIBFT_DIR)
	$(MAKE) -C $(LIBFT_DIR)

debug:
	$(MAKE) debug -C $(LIBFT_DIR)
	$(MAKE) GG=-g3 OPT=-O0

clean:
	$(MAKE) clean -C $(LIBFT_DIR)
	rm -f *.o

fclean: clean
	$(MAKE) fclean -C $(LIBFT_DIR)
	rm -f $(CLIENT) $(SERVER)

re: fclean all

git:
	git add --all
	git commit
	git push origin dev
