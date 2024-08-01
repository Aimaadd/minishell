/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_command.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abentaye <abentaye@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 18:36:09 by abentaye          #+#    #+#             */
/*   Updated: 2024/08/01 16:45:00 by abentaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

char	*find_binary(char *binary, char *path)
{
	char	**tab_path;
	char	*tmp;
	int		count;

	tab_path = ft_split(path, ':');
	if (!tab_path)
		return (NULL);
	binary = ft_strjoin("/", binary);
	count = 0;
	while (tab_path[count])
	{
		tmp = ft_strjoin(tab_path[count], binary);
		if (access(tmp, X_OK) == 0)
			return (tmp);
		free(tmp);
		count++;
	}
	return (NULL);
}

int	simple_command(t_cmd *cmd)
{
	char	*path;
	pid_t	pid;
	int		status;

	path = ft_getenv(cmd->env_copy, "PATH");
	if (!path)
		return (1);
	cmd->args[0] = find_binary(cmd->args[0], path);
	if (cmd->args[0] == NULL)
		return (1);
	pid = fork();
	if (pid == -1)
		return (1);
	else if (pid == 0)
		if (execve(cmd->args[0], cmd->args, cmd->env_copy))
			exit(0);
	waitpid(pid, &status, 0);
	return (0);
}
