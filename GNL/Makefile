# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nsainton <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/08 07:00:14 by nsainton          #+#    #+#              #
#    Updated: 2022/12/13 08:29:29 by nsainton         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=gnl

SRCS= get_next_line.c get_next_line_utils.c

BONUS_SRCS= get_next_line_bonus.c get_next_line_utils_bonus.c

OBJS= $(SRCS:.c=.o)

BONUS_OBJS= $(BONUS_SRCS:.c=.o)

CC= gcc

BS=42

CFLAGS= -Wall -Wextra -Werror

%.o: %.c
	$(CC) $(CFLAGS) $(GG) -D BUFFER_SIZE=$(BS) -c $< -o $@

all: $(OBJS)

clean:
	rm -f $(OBJS) $(BONUS_OBJS)

bonus: $(BONUS_OBJS)

re: clean all

git:
	git add --all
	git commit
	git push origin dev

merge:
	git checkout main
	git pull
	git merge dev
	git push origin main
	git checkout dev
