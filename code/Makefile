# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abentaye <abentaye@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/10 17:34:01 by abentaye          #+#    #+#              #
#    Updated: 2024/05/10 22:56:07 by abentaye         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

B = "\033[34m"
W = "\033[0m"
Y = "\033[33m"
G = "\033[32m"
R = "\033[31m"

NAME = minishell
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
SRCS =  ./src/main.c \
        ./src/prompt.c \

OBJS= $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	@echo $(Y)"Compiling $(NAME)..." $(W)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -lreadline
	@echo $(G)"[INFO]" $(W)"Compilation done"

$(OBJS): %.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@ 

clean :
	@$(RM) $(OBJS)
	@echo $(R)"[INFO]" $(W)"Objects deleted"

fclean : clean
	@$(RM) $(NAME)
	@echo $(R)"[INFO]" $(W)"$(NAME) deleted"

re : fclean all

.PHONY : all