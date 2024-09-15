/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_next_cmd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abentaye <abentaye@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 18:39:52 by abentaye          #+#    #+#             */
/*   Updated: 2024/09/15 18:39:54 by abentaye         ###   ########.fr       */
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
	int		arg_i;
	int		err;

	if (initialize_command(cmd, token) != OK)
		return (INT_ERROR);
	arg_i = 0;
	while (*token && (*token)->type != PIPE)
	{
		err = process_token(cmd, token, &arg_i);
		if (err != OK)
			return (err);
		*token = (*token)->next;
	}
	if (*token && (*token)->type == PIPE)
		*token = (*token)->next;
	cmd->args[arg_i] = NULL;
	return (OK);
}
