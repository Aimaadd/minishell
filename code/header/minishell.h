/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abentaye <abentaye@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 22:18:49 by abentaye          #+#    #+#             */
/*   Updated: 2024/05/17 17:39:27 by mmeerber         ###   ########.fr       */
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

typedef struct s_env
{
	char *variable;
	char *value;
	struct s_env	*next;
} t_env;
// input.c
t_input *input_to_list(char *input, t_input *entry);
char *catch_input(char *prompt);
int prompt(t_env *env);
void	ft_echo(char *str, int parametre, int fd);
t_env	*create_copy_env(char **env);

#endif
