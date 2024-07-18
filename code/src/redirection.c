/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abentaye <abentaye@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 12:39:47 by abentaye          #+#    #+#             */
/*   Updated: 2024/07/18 14:21:29 by abentaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

int	redirection(char *filename)
{
	int	fd;

	fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, S_IRWXU);
	if (fd < 0)
	{
		g_status = 1;
		return (1);
	}
	if (dup2(fd, STDOUT_FILENO) < 0)
	{
		g_status = 1;
		close(fd);
		exit(EXIT_FAILURE);
	}
	close(fd);
	return(0);
}