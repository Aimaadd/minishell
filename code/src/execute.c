/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abentaye <abentaye@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 08:54:38 by abentaye          #+#    #+#             */
/*   Updated: 2024/07/15 20:26:46 by mmeerber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

/*int	add_parametre(t_list *input, t_cmd *command)
{
	if (!command->parametre)
	{
		command->parametre = malloc(sizeof(char *) * 2);
		command->parametre[0] = input->prev->content;
		command->parametre[1] = input->content;
		return (1);
	}
}*/

/*void	check_type(t_list *input, t_cmd *command)
{
	if (input->type == BINARY)
		command->binary = input->content;
	if (input->type == PARAMETER)
		command->parametre = input->content;
	if (input->type == ARGUMENT)
		command->argument = input->content;
	if (input->type == INFILE)
		command->input_file = input->content;
	if (input->type == OUTFILE)
		command->output_file = input->content;
	if (input->type == PIPE)
		return ;
}*/

/*void	init_cmd(t_cmd *cmd)
{
	cmd->env_copy = NULL;
	cmd->args = NULL;
}

void	print_args(t_cmd *cmd)
{
	int x = 0;

	while (cmd->args[x])
	{
		printf("args[%d] = %s\n", x, cmd->args[x]);
		x++;
	}
	return ;
}

static char *find_binary(char *binary, char *path)
{
	int		x;
	int		check;
	char	*tmp;
	char	**tab_path;

	binary = ft_strjoin("/", binary);
	tab_path = ft_split(path, ':');
	if (!tab_path)
		return (NULL);
	x = 0;
	while (tab_path[x])
	{
		tmp = ft_strjoin(tab_path[x], binary);
		check = access(tmp, X_OK);
		if (check == 0)
			return (tmp);
		free(tmp);
		x++;
	}
	return (NULL);
}

int	fork_exec(t_cmd *cmd, t_env *env_copy)
{
	pid_t	pid;
	int		status;

	(void)env_copy;
	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		return (1);
	}
	if (pid == 0)
	{
		execve(cmd->args[0], cmd->args, cmd->env_copy);
		exit(0);
	}
	waitpid(pid, &status, 0);
	return (0);
}

int	run_cmd(t_cmd *cmd, t_env *env_copy)
{
	char	*path;

	path = ft_getenv(env_copy, "PATH");
	if (!path)
		return (1);
	cmd->args[0] = find_binary(cmd->args[0], path);
	if (!cmd->args[0])
		return (1);
	if (fork_exec(cmd, env_copy) == 0)
		return (0);
	// if (execve(cmd->args[0], cmd->args, cmd->env_copy))
	// 	perror("execve");
	return (0);
}

static int	get_entry(t_input *entry, t_env *env_copy, t_cmd *cmd)
{
	t_list	*tmp;
	int		x;

	cmd->env_copy = conv_tab_env(env_copy);
	tmp = entry->list;
	x = 0;
	while (tmp)
	{
		x++;
		tmp = tmp->next;
	}
	cmd->args = malloc(sizeof(char *) * (x + 1));
	if (!cmd->args)
		return (1);
	x = 0;
	tmp = entry->list;
	while (tmp)
	{
		cmd->args[x] = tmp->content;
		x++;
		tmp = tmp->next;
	}
	cmd->args[x] = NULL;
	return (0);
}

void	execute(t_input *entry, t_env *env_copy)
{
	t_cmd	*cmd;
	// t_list	*input;

	cmd = malloc(sizeof(t_cmd));
	if (!cmd)
		return ;
	init_cmd(cmd);
	get_entry(entry, env_copy, cmd);
	entry->signal = run_cmd(cmd, env_copy);
	//FLAG
	// printf("entry->signal = %d\n", entry->signal);
	free(cmd);
}*/

void	init_cmd(t_cmd *cmd)
{
	cmd->env_copy = NULL;
	cmd->args = NULL;
	cmd->size_list = 0;
	cmd->numbers_pipe = 0;
	cmd->lst_env = NULL;
	cmd->list = NULL;
}

int		setup_cmd(t_cmd *cmd, t_input *entry, t_env *env_copy)
{
	cmd->env_copy = conv_tab_env(env_copy);
	cmd->lst_env = env_copy;
	if (!cmd->env_copy)
		return (1);
	cmd->size_list = get_size_list(entry->list);
	cmd->numbers_pipe = check_if_pipe(entry->list);
	if (cmd->numbers_pipe == 0)
	{
		cmd->args = malloc(sizeof(char *) * (cmd->size_list + 1));
		if (!cmd->args)
			return (1);
		create_args(cmd, entry->list, cmd->size_list);
	}
	else
		cmd->list = entry->list;
	return (0);
}

int		run_cmd(t_cmd *cmd)
{
	if (cmd->numbers_pipe == 0)
		simple_command(cmd);
	else
		pipe_command(cmd);
	return (0);
}

int		execute(t_input *entry, t_env *env_copy)
{
	t_cmd	*cmd;

	cmd = malloc(sizeof(t_cmd));
	if (!cmd)
		return (1);
	init_cmd(cmd);
	if (setup_cmd(cmd, entry, env_copy) == 1)
		return (1);
	if (run_cmd(cmd) == 1)
		return (1);
	return (0);
}
