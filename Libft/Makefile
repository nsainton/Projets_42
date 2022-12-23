# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/23 06:01:21 by nsainton          #+#    #+#              #
#    Updated: 2022/12/23 07:54:17 by nsainton         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= libft.a

SRCS_DIR= sources

SRCS_NAMES= $(subst $(SRCS_DIR)/,, $(wildcard $(SRCS_DIR)/*))

SRCS= $(addprefix $(SRCS_DIR)/,$(SRCS_NAMES))

OBJS_DIR= objects

OBJS_NAMES= $(SRCS_NAMES:.c=.o)

OBJS= $(addprefix $(OBJS_DIR)/, $(OBJS_NAMES))

INC_DIR= includes

CC= gcc

CFLAGS= -Wall -Wextra -Werror

AR= ar -rc

all:
	$(MAKE) $(NAME)

$(NAME): $(OBJS) 
	$(AR) $(NAME) $(OBJS)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c $(wildcard $(INC_DIR)/*.h) | $(OBJS_DIR)
	$(CC) $(CFLAGS) $(OPT) $(GG) -c $< -o $@ -I $(INC_DIR)

$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)
debug:
	make re GG=-g3

clean:
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all debug clean fclean re
