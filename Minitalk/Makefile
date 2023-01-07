# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/31 22:53:20 by nsainton          #+#    #+#              #
#    Updated: 2023/01/07 04:30:30 by nsainton         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= Minitalk

CLIENT= client

SERVER= server

SRCS_DIR = sources

SRCS_NAMES = $(notdir $(wildcard $(SRCS_DIR)/*))

SRCS= $(addprefix $(SRCS_DIR)/, $(SRCS_NAMES))

OBJS_DIR= objects

OBJS_NAMES= $(SRCS_NAMES:.c=.o)

OBJS=$(addprefix $(OBJS_DIR)/, $(OBJS_NAMES))

INCLUDES= includes

LIBFT_DIR= ../Libft

LIBFT_NAME= libft.a

LIBFT_PATH= $(addprefix $(LIBFT_DIR)/, $(LIBFT_NAME))

LIBFT= lft

CC= gcc

CFLAGS= -Wall -Wextra -Werror

export C_INCLUDE_PATH=$(INCLUDES):$(LIBFT_DIR)/$(INCLUDES)
export LIBRARY_PATH=$(LIBFT_DIR)

all:
	$(MAKE) $(NAME)

$(NAME):
	$(MAKE) $(SERVER)
	$(MAKE) $(CLIENT)

$(SERVER): $(SERVER).c $(OBJS) $(LIBFT_PATH)
	$(CC) $(CFLAGS) $(OPT) $(GG) $(SERVER).c $(OBJS) -$(LIBFT) -o $(SERVER)

$(CLIENT): $(CLIENT).c $(OBJS) $(LIBFT_PATH)
	$(CC) $(CFLAGS) $(OPT) $(GG) $(CLIENT).c $(OBJS) -$(LIBFT) -o $(CLIENT)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c $(wildcard $(INCLUDES)/*) $(LIBFT_PATH) | $(OBJS_DIR)
	$(CC) $(CFLAGS) $(OPT) $(GG) -c $< -$(LIBFT) -o $@

$(LIBFT_PATH): | $(LIBFT_DIR)
	$(MAKE) -C $(LIBFT_DIR)

$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)

debug:
	$(MAKE) debug -C $(LIBFT_DIR)
	$(MAKE) GG="-g3 -fsanitize=undefined" OPT=-O0

clean:
	$(MAKE) clean -C $(LIBFT_DIR)
	rm -rf $(OBJS_DIR)

fclean: clean
	$(MAKE) fclean -C $(LIBFT_DIR)
	rm -f $(CLIENT) $(SERVER)

re: fclean all

git:
	git add --all
	git commit
	git push origin dev

.PHONY: all debug clean fclean re
