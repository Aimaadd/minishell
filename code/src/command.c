/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abentaye <abentaye@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 15:39:00 by abentaye          #+#    #+#             */
/*   Updated: 2024/08/29 22:50:45 by abentaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

void	update_envp(t_env *env_copy, char **envp)
{
	free_tab(envp);
	envp = conv_tab_env(env_copy);
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
	free_tab(new_path);
	free(bin);
	return (NULL);
}

void	run_execve(t_cmd *command)
{
	if (access(command->args[0], X_OK) == 0 && \
			(command->args[0][0] == '.' || command->args[0][0] == '/'))
	{
		execve(command->args[0], command->args, NULL);
		exit (0);
	}
	char *path = find_binary(command->args[0], ft_getenv(command->env_copy, "PATH"));
	if (path)
		execve(path, command->args, command->envp);
	exit (0);
}

int	simple_command(t_cmd *command)
{
	pid_t	pid;
	int		status;

	if (check_builtin(command) == 0)
		return (0);
	pid = fork();
	if (pid == 1)
		return (1);
	else if (pid == 0)
	{
		if (command->file && command->type_file == 1)
			redirection(command->file);
		else if (command->file && command->type_file == 2)
			append_mode(command->file);
		run_execve(command);
	}
	printf("!\n");
	waitpid(pid, &status, 0);
	return (0);
}
