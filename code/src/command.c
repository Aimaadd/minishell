/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abentaye <abentaye@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 15:39:00 by abentaye          #+#    #+#             */
/*   Updated: 2024/09/11 18:58:31 by abentaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

char	*find_binary(char *bin, char *path)
{
	char	**new_path;
	char	*path_bin;
	int		x;

	bin = ft_strjoin("/", bin);
	if (!bin)
		return (NULL);
	new_path = ft_split(path, ':');
	if (!new_path) {
		free(bin);
		return (NULL);
	}
	x = 0;
	while (new_path[x])
	{
		path_bin = ft_strjoin(new_path[x], bin);
		if (access(path_bin, X_OK) == 0) {
			free_tab(new_path);
			return (path_bin);
		}
		free(path_bin);
		x++;
	}
	free_tab(new_path);
	return (NULL);
}

void	run_execve(t_cmd *command)
{
	if (access(command->args[0], X_OK) == 0 && \
			(command->args[0][0] == '.' || command->args[0][0] == '/'))
	{
		execve(command->args[0], command->args, NULL);
		ft_exit_status(0);
	}
	command->args[0] = find_binary(command->args[0],
			ft_getenv(g_ms->env, "PATH"));
	if (!command->args[0])
		ft_exit_status(1);
	execve(command->args[0], command->args, command->envp);
	ft_exit_status(0);
}

int	simple_command(t_cmd *cmd)
{
	pid_t	pid;
	int		status;

	if (check_builtin(cmd) == 0)
		return (0);
	pid = fork();
	if (pid == 1)
		return (1);
	else if (pid == 0)
	{
		if (cmd->file && cmd->type_file == 1)
		{
			redirection(cmd->file);
		}
		else if (cmd->file && cmd->type_file == 2)
			append_mode(cmd->file);
		run_execve(cmd);
	}
	waitpid(pid, &status, 0);
	return (0);
}
