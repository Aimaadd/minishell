# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abentaye <abentaye@student.s19.be >        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/27 15:04:34 by abentaye          #+#    #+#              #
#    Updated: 2024/08/27 15:04:35 by abentaye         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libgc.a
TEST=test
CC=gcc
CFLAGS=-Wall -Werror -Wextra
AR=ar rcs
RM=rm -f

TEST_SRCS=test.c
SRCS=gc.c
OBJS=$(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(TEST): $(TEST_SRCS) $(NAME)
	$(CC) $(CFLAGS) $(TEST_SRCS) -L. -l:$(NAME) -o $@

clean:
	$(RM) $(OBJS)
	$(RM) $(TEST)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
