# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/06 17:45:33 by nsainton          #+#    #+#              #
#    Updated: 2022/10/06 18:43:32 by nsainton         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= libft

SRCS_DIR= sources

SRCS_NAMES= $(subst $(SRCS_DIR)/,,$(wildcard $(SRCS_DIR)/*))

SRCS= $(addprefix $(SRCS_DIR)/, $(SRCS_NAME))

OBJS_DIR= objects

OBJS_NAMES= $(SRCS_NAMES:.c=.o)

OBJS= $(addprefix $(OBJS_DIR)/,$(OBJS_NAMES))

SHELL= zsh

INCLUDES= includes

CC= clang

CFLAGS= -Wall -Wextra -Werror

override GG+= -g

override OPT= -O0

ifneq (,$(wildcard ./.env))
	include .env
	export
endif

all: $(NAME)

$(NAME): $(OBJS) $(INCLUDES)
	ar -rc $(NAME) $(OBJS) && \
	echo -e "\e$(YELLOW)$(NAME)\e$(GREEN) has been successfully created\e$(RESET)"

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c $(INCLUDES) | $(OBJS_DIR)
	$(CC) $(CFLAGS) $(GG) $(OPT) -c $< -o $@ -I $(INCLUDES)

$(OBJS_DIR):
	mkdir $(OBJS_DIR)

clean:
	rm -rf $(OBJS_DIR)
	echo -e "\e$(GREEN)make clean done\e$(RESET)"

fclean: clean
	rm -f $(NAME)
	echo -e "\e$(YELLOW)$(NAME)\e$(CYAN) has been successfully remnoved\e$(RESET)"

git:
	git add --all
	git commit
	git push origin main

.SILENT:
.PHONY: all clean fclean re git
