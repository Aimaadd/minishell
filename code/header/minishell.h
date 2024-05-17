/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abentaye <abentaye@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 22:18:49 by abentaye          #+#    #+#             */
/*   Updated: 2024/05/17 16:34:13 by abentaye         ###   ########.fr       */
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

# define BINARY 0
# define PARAMETER 1
# define ARGUMENT 2
# define REDIRECTION 3
# define PIPE 4

typedef struct	s_list
{
	char			*content;
	int 			type;
	struct s_list	*next;
	struct s_list	*prev;
}				t_list;

typedef struct s_input
{
	t_list	*list;
	int		index;
}					t_input;


// input.c
t_input *input_to_list(char *input, t_input *entry);

// prompt.c
char *catch_input(char *prompt);
int prompt(void);

#endif