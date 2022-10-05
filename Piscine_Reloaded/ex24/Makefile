# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/05 19:52:50 by nsainton          #+#    #+#              #
#    Updated: 2022/10/05 23:16:43 by nsainton         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS_DIR = srcs

SRCS_NAMES = ft_putchar.c ft_putstr.c ft_strcmp.c ft_strlen.c ft_swap.c

OBJS_DIR = objs

OBJS_NAMES = $(SRCS_NAMES:.c=.o)

SRCS = $(addprefix $(SRCS_DIR)/,$(SRCS_NAMES))

OBJS = $(addprefix $(OBJS_DIR)/, $(OBJS_NAMES))

CC= clang

CFLAGS= -Wall -Wextra -Werror

INCLUDES= includes

NAME= libft.a

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c $(INCLUDES) | $(OBJS_DIR)
	$(CC) $(CFLAGS) -c $< -o $@ -I $(INCLUDES)

$(OBJS_DIR):
	mkdir $(OBJS_DIR)

clean:
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
