/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   next_cmd_helpers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abentaye <abentaye@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 15:55:38 by abentaye          #+#    #+#             */
/*   Updated: 2024/09/15 16:00:18 by abentaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	handle_pipes_and_redirection(t_cmd *cmd, int *pipereadfd, int depth)
{
	unsetup_child_pipes(cmd, pipereadfd);
	if (cmd->redirout_type != 0)
		f_redirout(cmd, pipereadfd, depth);
}

int	handle_command_execution(t_cmd *cmd, t_token **token
	, int *pipereadfd, int depth)
{
	int	err;

	err = setup_next_cmd(cmd, token);
	if (err)
	{
		if (err == INT_ERROR)
			return (INT_ERROR);
		handle_exec_error(cmd, pipereadfd, *token, depth);
		return (INT_ERROR);
	}
	return (OK);
}

void	fork_and_execute(t_cmd *cmd, t_token *token, int pipereadfd, int depth)
{
	g_ms.pids[depth] = fork();
	if (g_ms.pids[depth] == 0)
		child_execution(cmd, token == NULL, pipereadfd);
	if (g_ms.pids[depth] == -1)
		hardfail_exit(errno);
}

void	handle_exec_error(t_cmd *cmd, int *pipereadfd
	, t_token *token, int depth)
{
	close_all_pipes(cmd, pipereadfd);
	print_error("minishell", strerror(errno), cmd->redirin_file);
	exec_next_cmd(token, 0, depth);
}
