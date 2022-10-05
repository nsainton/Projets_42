# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/06 00:13:08 by nsainton          #+#    #+#              #
#    Updated: 2022/10/06 00:48:53 by nsainton         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SHELL= zsh

SRCS_DIR= sources

SRCS_NAMES= $(subst $(SRCS_DIR)/,,$(wildcard $(SRCS_DIR)/*.c))

SRCS= $(addprefix $(SRCS_DIR)/, $(SRCS_NAMES))

OBJS_DIR= objects

OBJS_NAMES= $(SRCS_NAMES:.c=.o)

OBJS= $(addprefix $(OBJS_DIR)/, $(OBJS_NAMES))

NAME= ft_display_file

CC= clang

CFLAGS= -Wall -Wextra -Werror

PROG= main.c

INCLUDES= includes

override OPT= -O0

override GG+= -g

ifneq (,$(wildcard ./.env))
	include .env
	export
endif

all: $(NAME)

$(NAME): $(OBJS) $(PROG)
	$(CC) $(CFLAGS) $(GG) $(OPT) $(OBJS) $(PROG) -o $(NAME) -I $(INCLUDES) &&\
	echo -e "\e$(YELLOW)$(NAME)\e$(GREEN) has been successfully created\e$(RESET)"

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c $(INCLUDES) | $(OBJS_DIR)
	$(CC) $(CFLAGS) $(GG) $(OPT) -c $< -o $@ -I $(INCLUDES)

$(OBJS_DIR):
	mkdir $(OBJS_DIR)

clean:
	rm -rf $(OBJS_DIR) ; echo -e "\e$(GREEN)make clean done\e$(RESET)"

fclean: clean
	rm -rf $(NAME)
	echo -e "\e$(YELLOW)$(NAME)\e$(CYAN) has been successfully removed\e$(RESET)"

re: fclean all

.PHONY: all re clean fclean
.SILENT:
