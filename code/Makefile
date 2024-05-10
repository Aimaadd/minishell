# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abentaye <abentaye@student.s19.be >        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/10 17:34:01 by abentaye          #+#    #+#              #
#    Updated: 2024/05/10 18:00:39 by abentaye         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

Y = "\033[33m"
R = "\033[31m"
G = "\033[32m"
B = "\033[34m"
W = "\033[0m"

NAME = minishell
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
SRCS = ./src/main.c
OBJS= $(SRCS:.c=.o)

all = $(NAME)

$(NAME) : $(OBJS)
	@$(CC) $(CFLAGS) -o $(NAME) $(SRCS) > /dev/null 2>&1
	@echo $(Y)"Compiling $(NAME)..." $(W)
	@echo $(G)"[INFO]" $(W)"Compilation done"

clean :
	@$(RM) $(NAME) $(OBJS)

.PHONY : all