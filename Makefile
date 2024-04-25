# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wait-bab <wait-bab@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/23 11:59:19 by wait-bab          #+#    #+#              #
#    Updated: 2024/04/24 18:40:02 by wait-bab         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = client
NAME_BONUS = client_bonus
NAME_2 = server
NAME_BONUS_2 = server_bonus

CC = cc
CFLAGS = -Wall -Werror -Wextra
RM = rm -rf

OBJC = mandatory/client.c
OBJS = mandatory/server.c
OBJCb = bonus/client_bonus.c
OBJSb = bonus/server_bonus.c
HEDER = mandatory/minitalk.h
HEDER_B = bonus/minitalk_bonus.h

COLOUR_GREEN=\033[0;32m
COLOUR_RED=\033[0;31m
COLOUR_BLUE=\033[0;34m
COLOUR_END=\033[0m

all: $(NAME_2) $(NAME)

$(NAME_2): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@
	@echo "$(COLOUR_GREEN)███╗   ███╗██╗███╗   ██╗██╗████████╗ █████╗ ██╗     ██╗  ██╗"
	@echo "████╗ ████║██║████╗  ██║██║╚══██╔══╝██╔══██╗██║     ██║ ██╔╝ "
	@echo "██╔████╔██║██║██╔██╗ ██║██║   ██║   ███████║██║     █████╔╝"
	@echo "██║╚██╔╝██║██║██║╚██╗██║██║   ██║   ██╔══██║██║     ██╔═██╗ "
	@echo "██║ ╚═╝ ██║██║██║ ╚████║██║   ██║   ██║  ██║███████╗██║  ██╗ "
	@echo "╚═╝     ╚═╝╚═╝╚═╝  ╚═══╝╚═╝   ╚═╝   ╚═╝  ╚═╝╚══════╝╚═╝  ╚═╝ "
	@echo "$(COLOUR_GREEN)\
█▀ █░█ █▀▀ █▀▀ █▀▀ █▀ █▀ █▀▀ █░█ █░░ █░░ █▄█   █▀▀ █▀█ █▀▄▀█ █▀█ █ █░░ █▀▀ █▀▄\n\
▄█ █▄█ █▄▄ █▄▄ ██▄ ▄█ ▄█ █▀░ █▄█ █▄▄ █▄▄ ░█░   █▄▄ █▄█ █░▀░█ █▀▀ █ █▄▄ ██▄ █▄▀$(COLOUR_END)"
	
$(NAME): $(OBJC) $(HEDER)
	$(CC) $(CFLAGS) $(OBJC) -o $@
	
bonus : $(NAME_BONUS) $(NAME_BONUS_2)

$(NAME_BONUS_2): $(OBJSb) $(HEDER_B)
	$(CC) $(CFLAGS) $(OBJSb) -o $@
		@echo "$(COLOUR_BLUE)██████╗  ██████╗ ███╗   ██╗██╗   ██╗███████╗"
	@echo "██╔══██╗██╔═══██╗████╗  ██║██║   ██║██╔════╝"
	@echo "██████╔╝██║   ██║██╔██╗ ██║██║   ██║███████╗"
	@echo "██╔══██╗██║   ██║██║╚██╗██║██║   ██║╚════██║"
	@echo "██████╔╝╚██████╔╝██║ ╚████║╚██████╔╝███████║"
	@echo "╚═════╝  ╚═════╝ ╚═╝  ╚═══╝ ╚═════╝ ╚══════╝"
	@echo "$(COLOUR_BLUE)\
█▀ █░█ █▀▀ █▀▀ █▀▀ █▀ █▀ █▀▀ █░█ █░░ █░░ █▄█   █▀▀ █▀█ █▀▄▀█ █▀█ █ █░░ █▀▀ █▀▄\n\
▄█ █▄█ █▄▄ █▄▄ ██▄ ▄█ ▄█ █▀░ █▄█ █▄▄ █▄▄ ░█░   █▄▄ █▄█ █░▀░█ █▀▀ █ █▄▄ ██▄ █▄▀$(COLOUR_END)"
	
$(NAME_BONUS): $(OBJCb) $(HEDER_B)
	$(CC) $(CFLAGS) $(OBJCb) -o $@
	
clean:
	$(RM) $(NAME) $(NAME_2) $(NAME_BONUS) $(NAME_BONUS_2)

fclean: clean

re: fclean all