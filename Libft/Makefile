# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/06 17:45:33 by nsainton          #+#    #+#              #
#    Updated: 2022/10/15 20:16:18 by nsainton         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= libft

SRCS_DIR= sources

SRCS_NAMES= $(subst $(SRCS_DIR)/,,$(wildcard $(SRCS_DIR)/*))

SRCS= $(addprefix $(SRCS_DIR)/,$(SRCS_NAMES))

OBJS_DIR= objects

OBJS_NAMES= $(SRCS_NAMES:.c=.o)

OBJS= $(addprefix $(OBJS_DIR)/,$(OBJS_NAMES))

BONUS_DIR= bonus

BONUS_SRCS_DIR= $(addprefix $(BONUS_DIR)/, $(SRCS_DIR))

BONUS_SRCS_NAMES= $(subst $(BONUS_SRCS_DIR)/,, $(wildcard $(BONUS_SRCS_DIR)/*))

BONUS_SRCS= $(addprefix $(BONUS_SRCS_DIR), $(BONUS_SRCS_NAMES))

BONUS_OBJS_DIR= $(addprefix $(BONUS_DIR)/, $(OBJS_DIR))

BONUS_OBJS_NAMES= $(BONUS_SRCS_NAMES:.c=.o)

BONUS_OBJS= $(addprefix $(BONUS_OBJS_DIR)/,$(BONUS_OBJS_NAMES))

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

.PHONY: all
all: $(NAME)

$(NAME): $(OBJS) $(INCLUDES)
	ar -rc $(NAME) $(OBJS) && \
	echo -e "\e$(YELLOW)$(NAME)\e$(GREEN) has been successfully created\e$(RESET)"

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c $(INCLUDES)/$(NAME).h | $(OBJS_DIR)
	$(CC) $(CFLAGS) $(GG) $(OPT) -c $< -o $@ -I $(INCLUDES)

$(BONUS_OBJS_DIR)/%.o: $(BONUS_SRCS_DIR)/%.c $(INCLUDES) | $(BONUS_OBJS_DIR)
	$(CC) $(CFLAGS) $(GG) $(OPT) -c $< -o $@ -I $(INCLUDES)

$(OBJS_DIR):
	mkdir $(OBJS_DIR)

$(BONUS_OBJS_DIR):
	mkdir -p $@

bonus: all $(BONUS_OBJS) $(INCLUDES)/$(NAME)_bonus.h
	ar -rc $(NAME) $(BONUS_OBJS) && \
	echo -e "\e$(YELLOW)$(NAME) $(MAGENTA)DLC$(GREEN) has been successfully added\e$(RESET)"

.PHONY: clean
clean:
	rm -rf $(OBJS_DIR)
	rm -rf $(BONUS_OBJS_DIR)
	echo -e "\e$(RED)Objects directories\e$(GREEN) have been successfully removed\e$(RESET)"

.PHONY: fclean
fclean: clean
	rm -f $(NAME)
	echo -e "\e$(YELLOW)$(NAME)\e$(CYAN) has been successfully removed\e$(RESET)"

.PHONY: re
re: fclean all

.PHONY: git
git:
	git add --all
	git commit

.PHONY: getsrcs
getsrcs:
	echo $(SRCS_NAMES) > srcs
	echo $(BONUS_SRCS_NAMES) > bonus_srcs
