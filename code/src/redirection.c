/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abentaye <abentaye@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 12:39:47 by abentaye          #+#    #+#             */
/*   Updated: 2024/08/06 08:57:37 by abentaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

void	redirection(char *filename)
{
	int		fd;

	fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
		g_status = 1;
	if (dup2(fd, STDOUT_FILENO) < 0)
	{
		g_status = 1;
		close(fd);
		exit(EXIT_FAILURE);
	}
	close(fd);
}

void	append_mode(t_list *list)
{
	int		fd;
	t_list	*tmp;

	tmp = list;
	fd = open(tmp->next->content, O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (fd < 0)
		g_status = 1;
	if (dup2(fd, STDOUT_FILENO) < 0)
	{
		g_status = 1;
		close(fd);
		exit(EXIT_FAILURE);
	}
	close(fd);
}
