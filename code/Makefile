# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abentaye <abentaye@student.s19.be >        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/10 17:34:01 by abentaye          #+#    #+#              #
#    Updated: 2024/07/15 18:36:33 by abentaye         ###   ########.fr        #
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
CFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address
RM = rm -f
READLIB = $(HOME)/.brew/opt/readline/lib
READINCL = $(HOME)/.brew/opt/readline/include
LINKER = -L$(LIBFT) -lft -L$(READLIB) -I$(READINCL) -lreadline
LIBFT = ./libft/
LIBFTA = ./libft/libft.a
SRCS =  ./src/main.c \
        ./src/prompt.c \
		./src/ft_echo.c \
		./src/copy_env.c \
		./src/env_utils.c \
		./src/ft_cd.c \
		./src/ft_pwd.c \
		./src/ft_export.c \
		./src/ft_unset.c \
		./src/ft_env.c \
		./src/init_input.c \
		./src/input.c \
		./src/lexer.c \
		./src/execute.c \
		./src/prompt_handling.c \
		./src/sig_handler.c \
		./src/parse_input.c \
		./src/exec_utils.c \
		./src/run_command.c \

OBJS= $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	@echo $(O)"[INFO]" $(W)"Compiling libft"
	@make -C $(LIBFT)
	@echo $(O)"[INFO]" $(W)"Compiling $(NAME)..." $(W)
	@$(CC) $(CFLAGS) $(LINKER) -o $(NAME) $(OBJS) $(LIBFTA)
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
