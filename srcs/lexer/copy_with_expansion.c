/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_with_expansion.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abentaye <abentaye@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 16:44:56 by abentaye          #+#    #+#             */
/*   Updated: 2024/09/15 12:47:50 by abentaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	cpy_squote(char **line, char **word)
{
	++(*line);
	while (**line != '\'')
	{
		if (**line == '\0')
			return (LEXER_QUOTE_ERROR);
		*((*word)++) = *((*line)++);
	}
	++(*line);
	return (LEXER_OK);
}

int	_copy_with_expansion(char **line, char *word, int *in_dquote)
{
	while ((**line != '\0') && !(!(*in_dquote) && (ft_isoperator(**line)
				|| ft_isspace(**line))))
	{
		if (((**line == '\'') && !(*in_dquote)))
		{
			if (cpy_squote(line, &word))
				return (LEXER_QUOTE_ERROR);
			continue ;
		}
		if (**line == '\"')
		{
			(*in_dquote) = !(*in_dquote);
			++(*line);
			continue ;
		}
		if (expand(line, &word))
			continue ;
		*word = **line;
		++(*line);
		++(word);
	}
	*word = '\0';
	return (LEXER_OK);
}

int	copy_with_expansion(char **line, char *word)
{
	int		err;
	int		in_dquote;

	in_dquote = 0;
	err = _copy_with_expansion(line, word, &in_dquote);
	if (err != LEXER_OK)
		return (err);
	if (in_dquote)
		return (LEXER_QUOTE_ERROR);
	return (LEXER_OK);
}
