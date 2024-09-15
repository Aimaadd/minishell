/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator_token.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abentaye <abentaye@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 16:45:14 by abentaye          #+#    #+#             */
/*   Updated: 2024/09/15 12:48:10 by abentaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static enum e_type	redir_out_type(char **line)
{
	if (*((*line) + 1) == '>')
		return (D_REDIR_OUT);
	return (S_REDIR_OUT);
}

static enum e_type	redir_in_type(char **line)
{
	if (*((*line) + 1) == '<')
		return (D_REDIR_IN);
	return (S_REDIR_IN);
}

static void	cpytoken(char *to, char **line)
{
	while (ft_isoperator(**line))
		*(to++) = *((*line)++);
	*to = '\0';
}

int	set_operator_token(char **line, t_token **token)
{
	enum e_type	type;
	int			err;

	err = 0;
	if ((**line) == '<')
		type = redir_in_type(line);
	else if ((**line) == '>')
		type = redir_out_type(line);
	else if ((**line) == '|')
	{
		type = PIPE;
		g_ms.nb_cmds += 1;
	}
	else
		err = LEXER_SYNTAX_ERROR;
	(*token) = gc_malloc(&(g_ms.gcan), sizeof(t_token) + (sizeof(char) * 3));
	if ((*token) == NULL)
		return (LEXER_MALLOC_ERROR);
	cpytoken((*token)->value, line);
	(*token)->type = type;
	(*token)->next = NULL;
	return (err);
}
