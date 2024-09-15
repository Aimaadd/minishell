/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_next_cmd_helper.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abentaye <abentaye@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 18:39:52 by abentaye          #+#    #+#             */
/*   Updated: 2024/09/15 18:39:54 by abentaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	handle_redirections(t_cmd *cmd, t_token **token)
{
	if ((*token)->type == D_REDIR_OUT || (*token)->type == S_REDIR_OUT)
		redirout(cmd, token);
	else if ((*token)->type == D_REDIR_IN)
	{
		if (d_redirin(cmd, token))
			return (INT_ERROR);
	}
	else if ((*token)->type == S_REDIR_IN)
	{
		if (s_redirin(cmd, token))
			return (SOFTFAIL_ERROR);
	}
	return (OK);
}

int	process_token(t_cmd *cmd, t_token **token, int *arg_i)
{
	int	err;

	if ((*token)->type == WORD)
		word(cmd, token, arg_i);
	else
	{
		err = handle_redirections(cmd, token);
		if (err != OK)
			return (err);
	}
	return (OK);
}

int	initialize_command(t_cmd *cmd, t_token **token)
{
	cmd->arg_len = get_nb_args(*token);
	cmd->args = gc_malloc((&g_ms.gcan), sizeof(char *) * (cmd->arg_len + 1));
	if (cmd->args == NULL)
		hardfail_exit(errno);
	safe_pipe(cmd->pipeout);
	return (OK);
}
