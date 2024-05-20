/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abentaye <abentaye@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 22:18:49 by abentaye          #+#    #+#             */
/*   Updated: 2024/05/20 15:31:54 by mmeerber         ###   ########.fr       */
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

enum	type
{
	BINARY = 1,
	PARAMETER = 2,
	ARGUMENT = 3,
	REDIRECTION = 4,
	PIPE = 5,
};

typedef struct s_env
{
	char *variable;
	char *value;
	struct s_env	*next;
} t_env;

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
	t_env	*env;
	int		index;
}					t_input;

// input.c
t_input *input_to_list(char *input, t_input *entry);
char *catch_input(char *prompt);
int prompt(t_env *env);
void	ft_echo(char *str, int parametre, int fd);
t_env	*create_copy_env(char **env);
char	*ft_getenv(t_env *env, char *name_var);
void	ft_cd(char *path, t_env *env);
t_input	*input_to_list(char *input, t_input *entry);

// prompt.c
char	*catch_input(char *prompt);
int		prompt(void);

#endif
