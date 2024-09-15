/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_next_cmd_helpers.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abentaye <abentaye@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 09:34:53 by gmallet           #+#    #+#             */
/*   Updated: 2024/09/15 12:47:28 by abentaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	setup_child_pipes(t_cmd *cmd, int is_last_cmd, int *pipereadfd)
{
	if (is_opened_fd(cmd->pipein[0]))
	{
		safe_close(cmd->pipein + 1);
		safe_dup2(cmd->pipein[0], STDIN_FILENO);
		safe_close(cmd->pipein);
		safe_close(pipereadfd);
	}
	else if (is_opened_fd(*pipereadfd))
	{
		safe_dup2(*pipereadfd, STDIN_FILENO);
		safe_close(pipereadfd);
	}
	if (!is_last_cmd || (cmd->redirout_type != 0))
	{
		safe_close(cmd->pipeout);
		safe_dup2(cmd->pipeout[1], STDOUT_FILENO);
		safe_close(cmd->pipeout + 1);
	}
}

void	unsetup_child_pipes(t_cmd *cmd, int *pipereadfd)
{
	safe_close(cmd->pipeout + 1);
	safe_close(cmd->pipein);
	safe_close(cmd->pipein + 1);
	safe_close(pipereadfd);
}
