# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abentaye <abentaye@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/10 17:34:01 by abentaye          #+#    #+#              #
#    Updated: 2024/05/16 14:03:42 by mmeerber         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

B = "\033[34m"
W = "\033[0m"
Y = "\033[33m"
G = "\033[32m"
R = "\033[31m"
O = "\033[38;5;214m"

NAME = minishell
CC = cc
CFLAGS = -Wall -Wextra #-Werror
RM = rm -f
LIBFT = ./libft/
LIBFTA = ./libft/libft.a
SRCS =  ./src/main.c \
        ./src/prompt.c \
		./src/echo.c \
		./src/copy_env.c \

OBJS= $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	@echo $(O)"[INFO]" $(W)"Compiling libft"
	@make -C $(LIBFT)
	@echo $(O)"[INFO]" $(W)"Compiling $(NAME)..." $(W)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFTA) -lreadline
	@echo $(G)"[INFO]" $(W)"Compilation done"

$(OBJS): %.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@ 

clean :
	@$(RM) $(OBJS)
	@echo $(R)"[INFO]" $(W)"Objects deleted"

fclean : clean
	@$(RM) $(NAME) 
	@make fclean -C $(LIBFT)
	@echo $(R)"[INFO]" $(W)"$(NAME) deleted"

re : fclean all

.PHONY : all
