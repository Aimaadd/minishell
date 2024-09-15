# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abentaye <abentaye@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/10 17:34:01 by abentaye          #+#    #+#              #
#    Updated: 2024/09/15 17:19:38 by abentaye         ###   ########.fr        #
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
CFLAGS = -Wall -Wextra -Werror -g3
LIBGCDIR = ./gc/
LIBGC = ./gc/libgc.a
RM = rm -f
READLIB = $(HOME)/.brew/opt/readline/lib
READINCL = $(HOME)/.brew/opt/readline/include
LINKER = -L$(LIBFT) -L$(LIBGC) -L$(READLIB) -I$(READINCL) -lreadline
LIBFT = ./libft/
LIBFTA = ./libft/libft.a
SRCS =  ./srcs/builtins/cd.c \
		./srcs/builtins/echo.c \
		./srcs/builtins/env.c \
		./srcs/builtins/exit.c \
		./srcs/builtins/export.c \
		./srcs/builtins/pwd.c \
		./srcs/builtins/unset.c \
		./srcs/builtins/utils.c \
		./srcs/builtins/ft_split_path.c \
		./srcs/builtins/right_path.c \
		./srcs/envs/get_env_copy.c \
		./srcs/envs/ms_getenv.c \
		./srcs/executor/exec_builtin.c \
		./srcs/executor/exec.c \
		./srcs/executor/utils.c \
		./srcs/executor/setup_next_cmd.c \
		./srcs/executor/next_cmd_helpers.c \
		./srcs/executor/fd_manual_pipe.c \
		./srcs/executor/exec_next_cmd.c \
		./srcs/executor/exec_next_cmd_helpers.c \
		./srcs/executor/next_cmd_helpers2.c \
		./srcs/executor/utils2.c \
		./srcs/executor/setup_next_helper.c \
		./srcs/executor/exec_unpiped_builtin.c \
		./srcs/lexer/bad_token.c \
		./srcs/lexer/copy_with_expansion.c \
		./srcs/lexer/expand.c \
		./srcs/lexer/lexer.c \
		./srcs/lexer/operator_token.c \
		./srcs/lexer/syntax_utils.c \
		./srcs/lexer/utils.c \
		./srcs/lexer/word_token.c \
		./srcs/exits.c \
		./srcs/interpret.c \
		./srcs/main.c \
		./srcs/signals.c \

OBJS= $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	@echo $(O)"[INFO]" $(W)"Compiling libft"
	@make -C $(LIBFT)
	@echo $(G)"[INFO]" $(W)"Libft compiled"
	@echo $(O)"[INFO]" $(W)"Compiling gc"
	@make -C $(LIBGCDIR)
	@echo $(G)"[INFO]" $(W)"gc compiled"
	@echo $(O)"[INFO]" $(W)"Compiling $(NAME)..." $(W)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFTA) $(LIBGC) $(LINKER) 
	@echo $(G)"[INFO]" $(W)"Compilation done"

$(OBJS): %.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@ 

clean :
	@$(RM) $(OBJS)
	@make clean -C $(LIBGCDIR)
	@make clean -C $(LIBFT)
	@echo $(R)"[INFO]" $(W)"Objects deleted"

fclean : clean
	@$(RM) $(NAME)
	@make fclean -C $(LIBGCDIR)
	@make fclean -C $(LIBFT)
	@echo $(R)"[INFO]" $(W)"$(NAME) deleted"

re : fclean all

.PHONY : all