# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/29 21:53:38 by nsainton          #+#    #+#              #
#    Updated: 2022/12/30 06:49:37 by nsainton         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= Minitalk

SERVER= server

CLIENT= client

LIBFT_DIR= ../Libft

LIBFT= $(LIBFT_DIR)/libft.a

INCLUDES= includes

SOURCES_DIR= sources

SOURCES_NAMES= $(notdir $(wildcard $(SOURCES_DIR)/*))

SOURCES= $(addprefix $(SOURCES_DIR)/, $(SOURCES_NAMES))

CFLAGS= -Wall -Wextra -Werror

CC= gcc

#Ansi color codes
BEGIN=\033[
BLACK=30
RED=31
GREEN=32
BROWN=33
BLUE=34
PURPLE=35
CYAN=36
NORMAL=0
BOLD=1
UNDERLINED=4
BLINKING=5
REVERSE=7
END=\033[0m

#Font is Modular
define server_header
 ______    _______  _______  ______   __   __    _______  _______    ___      ___   _______  _______  _______  __    _ 
|    _ |  |       ||   _   ||      | |  | |  |  |       ||       |  |   |    |   | |       ||       ||       ||  |  | |
|   | ||  |    ___||  |_|  ||  _    ||  |_|  |  |_     _||   _   |  |   |    |   | |  _____||_     _||    ___||   |_| |
|   |_||_ |   |___ |       || | |   ||       |    |   |  |  | |  |  |   |    |   | | |_____   |   |  |   |___ |       |
|    __  ||    ___||       || |_|   ||_     _|    |   |  |  |_|  |  |   |___ |   | |_____  |  |   |  |    ___||  _    |
|   |  | ||   |___ |   _   ||       |  |   |      |   |  |       |  |       ||   |  _____| |  |   |  |   |___ | | |   |
|___|  |_||_______||__| |__||______|   |___|      |___|  |_______|  |_______||___| |_______|  |___|  |_______||_|  |__|
endef
export server_header

#Font is Big
define client_header
  _____                _         _          _        _ _    
 |  __ \              | |       | |        | |      | | |   
 | |__) |___  __ _  __| |_   _  | |_ ___   | |_ __ _| | | __
 |  _  // _ \/ _` |/ _` | | | | | __/ _ \  | __/ _` | | |/ /
 | | \ \  __/ (_| | (_| | |_| | | || (_) | | || (_| | |   < 
 |_|  \_\___|\__,_|\__,_|\__, |  \__\___/   \__\__,_|_|_|\_\ 
                          __/ |                             
                         |___/                              
endef
export client_header
all:
	$(MAKE) $(NAME)

$(NAME):
	$(MAKE) -C $(LIBFT_DIR)
	$(MAKE) $(SERVER)
	$(MAKE) $(CLIENT)

$(SERVER): $(SERVER).c $(SOURCES) $(LIBFT)
	$(CC) $(CFLAGS) $(GG) $(OPT) $(SOURCES) $(SERVER).c $(LIBFT) -o $(SERVER)
	@echo "$(BEGIN)$(BOLD);$(RED)m $$server_header $(END)"

$(CLIENT): $(CLIENT).c $(SOURCES) $(LIBFT)
	$(CC) $(CFLAGS) $(GG) $(OPT) $(SOURCES) $(CLIENT).c $(LIBFT) -o $(CLIENT)
	@echo "$(BEGIN)$(BOLD);$(CYAN)m $$client_header $(END)"

$(OBJECTS_DIR)/%.o: $(SOURCES_DIR)/%.c $(wildcard $(INCLUDES)/*) $(LIBFT) | $(OBJECTS_DIR)
	$(CC) $(CFLAGS) $(GG) $(OPT) -c $< $(LIBFT) -o $@ -I $(INCLUDES)

$(OBJECTS_DIR):
	mkdir $(OBJECTS_DIR)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

debug:
	$(MAKE) debug -C $(LIBFT_DIR)
	$(MAKE) GG=-g3 OPT=-O0

clean:
	$(MAKE) clean -C $(LIBFT_DIR)
	rm -rf $(OBJECTS_DIR)
	echo "$(BEGIN)$(RED)mObjects have been successfully removed$(END)"

fclean: clean
	$(MAKE) fclean -C $(LIBFT_DIR)
	rm -f $(CLIENT) $(SERVER)
	echo "$(BEGIN)$(UNDERLINED);$(RED)m$(SERVER)$(BEGIN)$(NORMAL);$(CYAN)m and \
	$(BEGIN)$(UNDERLINED);$(RED)m$(CLIENT)$(BEGIN)$(NORMAL);$(CYAN)m have been \
	successfully removed$(END)"

re: fclean all

git:
	git add ./*
	git commit
	git push origin dev

.PHONY: $(NAME) debug clean fclean re git
.SILENT:
