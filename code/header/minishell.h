/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abentaye <abentaye@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 22:18:49 by abentaye          #+#    #+#             */
/*   Updated: 2024/09/11 19:47:54 by abentaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <errno.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <fcntl.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <sys/wait.h>
# include "../libft/libft.h"
# include <termios.h>
# include "../gc/gc.h"

# define ERROR_LOOP -1
# define UNCLOSED_QTS 1
# define BUFFERSIZE 1024

enum e_type
{
	BINARY = 1,
	PARAMETER,
	ARGUMENT,
	REDIRECTION,
	PIPE,
	OUTFILE,
	APPEND,
	HEREDOC,
	ENV,
	STATUS,
	INFILE
};

typedef struct s_env
{
	char				*variable;
	char				*value;
	struct s_env		*next;
}	t_env;

typedef struct s_list
{
	char				*content;
	int					type;
	int					read;
	int					second_read;
	struct s_list		*next;
	struct s_list		*prev;
}	t_list;

typedef struct s_cmd
{
	char				**args;
	char				**envp; //
	t_env				*env_copy; //
	char				*file;
	int					type_file;
	struct s_cmd		*next;
}	t_cmd;

typedef struct s_input
{
	t_list				*list;
	t_env				*env;
	t_cmd				*cmd;
	t_gcan				gc;
	t_gcan				gcenv;
	t_gcan				gcmd;
	char				*line;
	int					index;
	int					signal;
	int					ret_val;
}	t_input;

extern t_input	*g_ms;

typedef struct s_data_multiple
{
	int					number_of_command;
	int					count_command;
	int					count_pid;
	int					last_fd;
}			t_data_multiple;

//main.c 
int		minishell_loop(void);

//init_input.c
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*ft_lstnew(void *content);
t_list	*ft_lstlast(t_list *head);
t_list	*array_to_list(char **array);

// input.c
void	free_list(t_list *list);
char	*catch_input(char *prompt);
void	empty_node(t_list *list);

// parse_input.c
int		is_parameter(const char *str);
int		pipe_or_redirection(char *line);
char	**split_pipe_redir(char *line);
char	*between_quotes(char *line);
char	*to_expand(t_list *input);

// ft_echo.c
void	ft_echo(t_cmd *command);

// copy_env.c
t_env	*create_copy_env(char **envp);
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
t_list	*input_to_list(void);

// prompt.c
char	*catch_input(char *prompt);
char	*prompt(void);

// prompt_handling.c
char	*prompt_handler(char *entry);

// lexer.c
int		read_list(t_list *list);
int		read_type(char *content);

//init.c
t_input	*init_input(void);

// execute.c
int		execute(void);
int		setup_cmd(t_cmd *cmd, t_env *env_copy);
int		run_cmd(t_cmd *cmd);

// exec_utils.c
int		check_if_pipe(t_list *list);
void	create_args(t_cmd *cmd, t_list	*list);
int		get_size_list(t_list *list);

// run_command.c

// exec_utils.c
int		get_number_pipe(t_list *list);
int		get_size_command(t_list *list);

// sig_handler.c
void	*init_signal(void);

// redirection.c
void	redirection(char *filename);
void	append_mode(char *filename);
int		dup_and_close(char *filename);

// create_command.c
t_cmd	*create_cmd(t_list *list);

// init_command.c
int		init_execute(void);
int		add_args(void);

// command_utils.c
int		get_number_command(t_cmd *cmd);

// builtin.c
int		check_builtin(t_cmd *cmd);
int		check_max_len(char *s1, char *s2);

// command.c
int		simple_command(t_cmd *command);
char	*find_binary(char *bin, char *path);

// command_utils.c
int		get_number_command(t_cmd *cmd);

// builtin.c
int		check_builtin(t_cmd *command);
int		check_max_len(char *s1, char *s2);

// ft_exit.c
void	ft_exit(void);
void	ft_exit_status(int status);

// ft_free.c
void	free_command(t_cmd *command);

// multiple_command.c
int		multiple_command(void);

//readline functions
void	rl_replace_line(const char *text, int clear_undo);

// heredoc.c
int		temp_file_create(void);
char	*heredoc_loop(void);
void	handle_heredoc(char *delim);

// debug_tools.c
void	printab(char **str);
void	printenv(t_env *env);
void	printlist(t_list *list);
void	printcmd(t_cmd *cmd);

// solo_execute.c 
char	**fill_array_from_list(t_list *list);
char	**fill_array_from_env(t_env *env);

#endif
