/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   next_cmd_helpers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abentaye <abentaye@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 15:55:38 by abentaye          #+#    #+#             */
/*   Updated: 2024/09/15 17:09:33 by abentaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	close_pipes_and_print_error(t_cmd *cmd, int *pipereadfd)
{
	close_all_pipes(cmd, pipereadfd);
	print_error("minishell", strerror(errno), cmd->redirin_file);
}

void	call_exec_next_cmd(t_token *token, int depth)
{
	exec_next_cmd(token, 0, depth);
}

void	fork_and_execute(t_cmd *cmd, int pipereadfd, int depth, t_token *tkn)
{
	if (cmd->executable != NULL)
	{
		g_ms.pids[depth] = fork();
		if (g_ms.pids[depth] == 0)
			child_execution(cmd, tkn == NULL, pipereadfd);
	}
}

void	handle_fork_error(int depth)
{
	if (g_ms.pids[depth] == -1)
		hardfail_exit(errno);
}

void	handle_fork(t_cmd *cmd, int pipereadfd, int depth, t_token *token)
{
	fork_and_execute(cmd, pipereadfd, depth, token);
	handle_fork_error(depth);
}
