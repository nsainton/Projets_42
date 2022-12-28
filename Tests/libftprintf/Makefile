# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/28 22:05:52 by nsainton          #+#    #+#              #
#    Updated: 2022/12/28 22:12:27 by nsainton         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libftprintf.a
LIBFT_ARCHIVE=libft.a
LIBFT=../../Libft

all: $(NAME)

$(NAME):
	$(MAKE) -C $(LIBFT)
	mv $(LIBFT)/$(LIBFT_ARCHIVE) $(NAME)

clean:
	$(MAKE) clean -C $(LIBFT)

fclean:
	$(MAKE) fclean -C $(LIBFT)

re: fclean all

bonus: re
