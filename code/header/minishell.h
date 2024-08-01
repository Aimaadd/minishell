/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abentaye <abentaye@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 22:18:49 by abentaye          #+#    #+#             */
/*   Updated: 2024/08/01 18:39:23 by mmeerber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <fcntl.h>
# include "../readline/includes/history.h"
# include "../readline/includes/readline.h"
# include <signal.h>
# include "../libft/libft.h"

# define ERROR_LOOP -1
# define UNCLOSED_QTS 1

int	g_status;

enum	e_type
{
	BINARY = 1,
	PARAMETER = 2,
	ARGUMENT = 3,
	REDIRECTION = 4,
	PIPE = 5,
	OUTFILE = 6,
	INFILE = 7,
	FOLDER = 8,
	ENV = 9
};

typedef struct s_env
{
	char			*variable;
	char			*value;
	struct s_env	*next;
}	t_env;

typedef struct s_list
{
	char			*content;
	int				type;
	int				read;
	int				second_read;
	struct s_list	*next;
	struct s_list	*prev;
}	t_list;

typedef struct s_input
{
	t_list				*list;
	t_env				*env;
	char				*line;
	int					index;
	int					signal;
}	t_input;

typedef struct s_cmd
{
	char			**args;
	char			**envp;
	t_env			*env_copy;
	char			*file;
	struct s_cmd	*next;
}	t_cmd;

typedef struct s_data_multiple
{
	int		number_of_command;
	int		count_command;
	int		count_pid;
	int		last_fd;
} t_data_multiple;

//main.c 
void	minishell_loop(t_input *entry, t_env *env_copy);

//init_input.c
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*ft_lstnew(void *content);
t_list	*ft_lstlast(t_list *head);
t_list	*array_to_list(char **array);

// input.c
void	free_list(t_list *list);
char	*catch_input(char *prompt);

// parse_input.c
int		pipe_or_redirection(char *line);
char	**split_pipe_redir(char *line);
char	*between_quotes(char *line);
char	*to_expand(t_list *input);

// ft_echo.c
void	ft_echo(t_cmd *command);

// copy_env.c
t_env	*create_copy_env(char **env);
int		add_element(t_env **copy_env, char *content);

// env_utils.c
char	*ft_getenv(t_env *env, char *name_var);
void	update_value_env(char *value, char *variable, t_env *env);
int		check_size(char *s1, char *s2);
char	**conv_tab_env(t_env *env_copy);
void	print_env(t_env *env);
void	free_tab(char **tab);

// ft_cd.c
void	ft_cd(char *path, t_env *env);

// ft_pwd.c
void	ft_pwd(void);

// ft_export.c
void	ft_export(char *input, t_env **copy_env);

// ft_unset.c
void	ft_unset(char *variable, t_env **copy_env);

// ft_env.c
void	ft_env(t_env *env);
char	*catch_input(char *prompt);
t_list	*input_to_list(t_input *entry);

// prompt.c
char	*catch_input(char *prompt);
char	*prompt(void);

// prompt_handling.c
char	*prompt_handler(char *entry);

// lexer.c
int		read_list(t_list *list);
int		read_type(char *content);
int		is_parameter(const char *str);

//init.c
t_input	*init_input(void);

// execute.c
int		execute(t_input *entry, t_env *env_copy);
int		setup_cmd(t_cmd *cmd, t_input *entry, t_env *env_copy);
int		run_cmd(t_cmd *cmd);

// exec_utils.c
int		check_if_pipe(t_list *list);
void	create_args(t_cmd *cmd, t_list	*list);
int		get_size_list(t_list *list);

// run_command.c
int		simple_command(t_cmd *cmd);
int		execute(t_input *entry, t_env *env_copy);

// exec_utils.c
int     get_number_pipe(t_list *list);
int     get_size_command(t_list *list);

// sig_handler.c
void	*init_signal(t_input *entry);

// redirection.c
void		redirection(char *filename);
int		dup_and_close(char *filename);

// create_command.c
t_cmd	*create_cmd(t_list *list);

// init_command.c
int		init_execute(t_input *entry, t_env *env_copy, t_cmd *command);

// command_utils.c
int		get_number_command(t_cmd *cmd);

// builtin.c
int		check_builtin(t_cmd *command);
int		check_max_len(char *s1, char *s2);

// create_command.c
t_cmd	*create_cmd(t_list *list);

// init_command.c
int		init_execute(t_input *entry, t_env *env_copy, t_cmd *command);

// command.c
int     simple_command(t_cmd *command);

// command_utils.c
int		get_number_command(t_cmd *cmd);

// builtin.c
int		check_builtin(t_cmd *command);
int		check_max_len(char *s1, char *s2);

// ft_exit.c
void	ft_exit(t_cmd *command);

// ft_free.c
void	free_command(t_cmd *command);

// multiple_command.c
int		multiple_command(t_cmd *command);

#endif
