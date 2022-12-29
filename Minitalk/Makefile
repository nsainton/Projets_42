# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/29 21:53:38 by nsainton          #+#    #+#              #
#    Updated: 2022/12/30 00:35:23 by nsainton         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= Minitalk

SERVER= server

CLIENT= client

LIBFT_DIR= ../Libft

LIBFT= ../Libft/libft.a

SSOURCES_DIR= server_sources

CSOURCES_DIR= client_sources

SOURCES_DIR= sources

INCLUDES= includes

SOURCES_NAMES= $(notdir $(wildcard $(SOURCES_DIR)/*))

SSOURCES_NAMES= $(subst $(SSOURCES_DIR)/,, $(wildcard $(SSOURCES_DIR)/*))

CSOURCES_NAMES= $(notdir $(wildcard $(CSOURCES_DIR)/*))

SOURCES= $(addprefix $(SOURCES_DIR)/, $(SOURCES_NAMES))

SSOURCES= $(addprefix $(SSOURCES_DIR)/,$(SSOURCES_NAMES))

CSOURCES= $(addprefix $(CSOURCES_DIR)/, $(CSOURCES_NAMES))

OBJECTS_DIR= objects

SOBJECTS_DIR= server_objects

COBJECTS_DIR= client_objects

OBJECTS_NAMES= $(SOURCES_NAMES:.c=.o)

SOBJECTS_NAMES= $(SSOURCES_NAMES:.c=.o)

COBJECTS_NAMES= $(CSOURCES_NAMES:.c=.o)

OBJECTS= $(addprefix $(OBJECTS_DIR)/, $(OBJECTS_NAMES))

SOBJECTS= $(addprefix $(SOBJECTS_DIR)/, $(SOBJECTS_NAMES))

COBJECTS= $(addprefix $(COBJECTS_DIR)/, $(COBJECTS_NAMES))

CC= gcc

CFLAGS= -Wall -Wextra -Werror

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

$(SERVER): $(SOBJECTS) $(OBJECTS)
	$(CC) $(CFLAGS) $(GG) $(OPT) $(SOBJECTS) $(OBJECTS) -o $(SERVER)
	@echo "$(BEGIN)$(BOLD);$(RED)m $$server_header $(END)"

$(CLIENT): $(COBJECTS) $(OBJECTS)
	$(CC) $(CFLAGS) $(GG) $(OPT) $(COBJECTS) $(OBJECTS) -o $(CLIENT)
	@echo "$(BEGIN)$(BOLD);$(CYAN)m $$client_header $(END)"

$(OBJECTS_DIR)/%.o: $(SOURCES_DIR)/%.c $(wildcard $(INCLUDES)/*) $(LIBFT) | $(OBJECTS_DIR)
	$(CC) $(CFLAGS) $(GG) $(OPT) -c $< $(LIBFT) -o $@ -I $(INCLUDES)

$(SOBJECTS_DIR)/%.o: $(SSOURCES_DIR)/%.c $(wildcard $(INCLUDES)/*) $(LIBFT) | $(SOBJECTS_DIR)
	$(CC) $(CFLAGS) $(GG) $(OPT) -c $< $(LIBFT) -o $@ -I $(INCLUDES)

$(COBJECTS_DIR)/%.o: $(CSOURCES_DIR)/%.c $(wildcard $(INCLUDES)/*) $(LIBFT) | $(COBJECTS_DIR)
	$(CC) $(CFLAGS) $(GG) $(OPT) -c $< $(LIBFT) -o $@ -I $(INCLUDES)

$(OBJECTS_DIR):
	mkdir $(OBJECTS_DIR)

$(SOBJECTS_DIR):
	mkdir $(SOBJECTS_DIR)

$(COBJECTS_DIR):
	mkdir $(COBJECTS_DIR)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)
debug:
	$(MAKE) debug -C $(LIBFT_DIR)
	$(MAKE) GG=-g3 OPT=-O0

clean:
	$(MAKE) clean -C $(LIBFT_DIR)
	rm -rf $(SOBJECTS_DIR) $(COBJECTS_DIR) $(OBJECTS_DIR)
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
