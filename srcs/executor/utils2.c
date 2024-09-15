/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abentaye <abentaye@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 16:42:09 by abentaye          #+#    #+#             */
/*   Updated: 2024/09/15 12:47:35 by abentaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	is_builtin(char *cmd)
{
	if (!strcmp(cmd, "echo"))
		return (1);
	if (!strcmp(cmd, "env"))
		return (1);
	if (!strcmp(cmd, "pwd"))
		return (1);
	return (is_unpiped_builtin(cmd));
}

int	is_opened_fd(int fd)
{
	return (fd != -1);
}

void	safe_close(int *fd)
{
	if (*fd == -1)
		return ;
	if (close(*fd))
		hardfail_exit(errno);
	*fd = -1;
}

void	safe_pipe(int pids[2])
{
	if (pipe(pids) == -1)
		hardfail_exit(errno);
}

void	safe_dup2(int oldfd, int newfd)
{
	if (dup2(oldfd, newfd) == -1)
		hardfail_exit(errno);
}
