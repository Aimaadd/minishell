/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_next_cmd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abentaye <abentaye@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 09:35:13 by gmallet           #+#    #+#             */
/*   Updated: 2024/09/15 17:20:12 by abentaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	word(t_cmd *cmd, t_token **token, int *i)
{
	if (cmd->executable == NULL)
		cmd->executable = (*token)->value;
	cmd->args[(*i)++] = (*token)->value;
}

void	redirout(t_cmd *cmd, t_token **token)
{
	cmd->redirout_type = (*token)->type;
	(*token) = (*token)->next;
	cmd->redirout_file = (*token)->value;
}

int	d_redirin(t_cmd *cmd, t_token **token)
{
	safe_pipe(cmd->pipein);
	if (fd_m_pipe(STDIN_FILENO, cmd->pipein[1], (*token)->next->value))
		return (INT_ERROR);
	(*token) = (*token)->next;
	return (0);
}

int	s_redirin(t_cmd *cmd, t_token **token)
{
	int	err;

	safe_pipe(cmd->pipein);
	(*token) = (*token)->next;
	cmd->redirin_file = (*token)->value;
	err = file_to_pipe(cmd->redirin_file, cmd->pipein[1]);
	if (err != OK)
	{
		(*token) = (*token)->next;
		return (err);
	}
	return (OK);
}

int	setup_next_cmd(t_cmd *cmd, t_token **token)
{
	cmd->arg_len = get_nb_args(*token);
	cmd->args = gc_malloc((&g_ms.gcan), sizeof(char *) * (cmd->arg_len + 1));
	if (cmd->args == NULL)
		hardfail_exit(errno);
	safe_pipe(cmd->pipeout);
	return (process_tokens(cmd, token));
}
