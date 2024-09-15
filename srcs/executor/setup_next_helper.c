/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_next_helper.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abentaye <abentaye@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 17:11:06 by abentaye          #+#    #+#             */
/*   Updated: 2024/09/15 17:20:22 by abentaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	handle_token(t_cmd *cmd, t_token **token, int *arg_i)
{
	if ((*token)->type == WORD)
		word(cmd, token, arg_i);
	else if (((*token)->type == D_REDIR_OUT) || ((*token)->type == S_REDIR_OUT))
		redirout(cmd, token);
	else if ((*token)->type == D_REDIR_IN)
	{
		if (d_redirin(cmd, token))
			return (INT_ERROR);
	}
	else if ((*token)->type == S_REDIR_IN && s_redirin(cmd, token))
		return (SOFTFAIL_ERROR);
	return (OK);
}

int	process_tokens(t_cmd *cmd, t_token **token)
{
	int	arg_i;
	int	ret;

	arg_i = 0;
	while ((*token) && ((*token)->type != PIPE))
	{
		ret = handle_token(cmd, token, &arg_i);
		if (ret != OK)
			return (ret);
		(*token) = (*token)->next;
	}
	if ((*token) && ((*token)->type == PIPE))
		(*token) = (*token)->next;
	cmd->args[arg_i] = NULL;
	return (OK);
}
