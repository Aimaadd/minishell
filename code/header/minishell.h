/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abentaye <abentaye@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 22:18:49 by abentaye          #+#    #+#             */
/*   Updated: 2024/05/31 00:44:51 by abentaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <signal.h>
# include "../libft/libft.h"

enum	e_type
{
	BINARY = 1,
	PARAMETER = 2,
	ARGUMENT = 3,
	REDIRECTION = 4,
	PIPE = 5,
};

typedef struct s_list
{
	char			*content;
	int				type;
	struct s_list	*next;
	struct s_list	*prev;
}				t_list;

typedef struct s_input
{
	t_list	*list;
	char	*line;
	int		index;
}					t_input;

//init_input.c
void	ft_lstadd_back(t_list **stack, t_list *new);
t_list	*ft_lstnew(char *content);
t_list	*ft_lstlast(t_list *head);

// input.c
t_list	*input_to_list(t_input *entry);
void	filling_loop(t_input *entry);

// prompt.c
char	*catch_input(char *prompt);
char	*prompt(void);

// lexer.c
int		read_list(t_list *list);
int		read_content(char *content);


//init.c
void	init_input(t_input *entry);

#endif