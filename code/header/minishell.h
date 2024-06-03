/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abentaye <abentaye@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 22:18:49 by abentaye          #+#    #+#             */
/*   Updated: 2024/05/27 12:21:43 by abentaye         ###   ########.fr       */
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

typedef struct s_env
{
	char *variable;
	char *value;
	struct s_env	*next;
} t_env;

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
	t_env	*env;
	char	*line;
	int		index;
}					t_input;

// input.c
void	filling_loop(t_input *entry);
char	*catch_input(char *prompt);

// ft_echo.c
void	ft_echo(char *str, int parametre, int fd);

// copy_env.c
t_env	*create_copy_env(char **env);
int		add_element(t_env **copy_env, char *content);

// env_utils.c
char	*ft_getenv(t_env *env, char *name_var);
void	update_value_env(char *value, char *variable, t_env *env);
int		check_size(char *s1, char *s2);

// ft_cd.c
void	ft_cd(char *path, t_env *env);

// ft_pwd.c
void	ft_pwd();

// ft_export.c
void	ft_export(char *input, t_env **copy_env);

// ft_unset.c
void    ft_unset(char *variable, t_env **copy_env);

// ft_env.c
void	ft_env(t_env *env);
char	*catch_input(char *prompt);
t_list	*input_to_list(t_input *entry);

// prompt.c
char	*catch_input(char *prompt);
char	*prompt(void);

// lexer.c
int		read_list(t_list *list);

//init.c
void	init_input(t_input *entry);

#endif
