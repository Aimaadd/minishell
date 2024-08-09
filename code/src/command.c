/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abentaye <abentaye@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 15:39:00 by abentaye          #+#    #+#             */
/*   Updated: 2024/08/09 19:47:49 by abentaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

int	update_envp(t_env *env_copy, char **envp)
{
	free_tab(envp);
	envp = conv_tab_env(env_copy);
	return (0);
}

char	*find_binary(char *bin, char *path)
{
	char	**new_path;
	char	*path_bin;
	int		x;

	bin = ft_strjoin("/", bin);
	if (!bin)
		return (NULL);
	new_path = ft_split(path, ':');
	if (!new_path)
		return (NULL);
	x = 0;
	while (new_path[x])
	{
		path_bin = ft_strjoin(new_path[x], bin);
		if (access(path_bin, X_OK) == 0)
			return (path_bin);
		free(path_bin);
		x++;
	}
	return (NULL);
}

int	simple_command(t_cmd *command)
{
	pid_t	pid;
	int		status;

	if (!check_builtin(command))
		return (update_envp(command->env_copy, command->envp));
	pid = fork();
	if (pid == 1)
		return (1);
	if (pid == 0)
	{
		if (command->file && command->type_file == BINARY)
			redirection(command->file);
		else if (command->file && command->type_file == PARAMETER)
			append_mode(command->file);
		if (access(command->args[0], X_OK) == 0 && (command->args[0][0] == '.' || command->args[0][0] == '/'))
		{
			execve(command->args[0], command->args, NULL);
			exit (0);
		}
		command->args[0] = find_binary(command->args[0], ft_getenv(command->env_copy, "PATH"));
		if (!command->args[0])
			exit (1);
		execve(command->args[0], command->args, command->envp);
		exit (0);
	}
	waitpid(pid, &status, 0);
	return (0);
}
