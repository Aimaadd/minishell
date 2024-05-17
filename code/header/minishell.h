/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abentaye <abentaye@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 22:18:49 by abentaye          #+#    #+#             */
/*   Updated: 2024/05/17 16:41:27 by mmeerber         ###   ########.fr       */
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

typedef struct s_input
{
	char	*input;
	int		index;
	struct s_input	*next;
	struct s_input	*prev;
}					t_input;

typedef struct s_cmd
{
	char **str;
	int	type;
}				t_cmd;

typedef struct s_env
{
	char *variable;
	char *value;
	struct s_env	*next;
} t_env;

char *catch_input(char *prompt);
int prompt(t_env *env);
void	ft_echo(char *str, int parametre, int fd);
t_env	*create_copy_env(char **env);

#endif
