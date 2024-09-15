/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   word_token.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abentaye <abentaye@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 16:45:37 by abentaye          #+#    #+#             */
/*   Updated: 2024/09/15 14:20:36 by abentaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static size_t	get_single_quote_len(char **line)
{
	size_t	size;

	++(*line);
	size = 0;
	while (**line)
	{
		if ((**line) == '\'')
		{
			++(*line);
			break ;
		}
		++(*line);
		++size;
	}
	return (size);
}

static size_t	get_env_size(char **line)
{
	char *ptr;
	
	++(*line);
	if ((**line) == '?')
	{
		++(*line);
		return (get_nb_len(g_ms.old_status));
	}
	ptr = get_env_from_line(line);
	if (ptr == NULL)
		return (0);
	return (ft_strlen(ptr));
}

static size_t	get_expanded_size(char *line)
{
	size_t	size;
	int		in_dquote;

	size = 0;
	in_dquote = 0;
	while (*line && !(!in_dquote && (ft_isoperator(*line)
				|| ft_isspace(*line))))
	{
		if ((*line == '\'') && !in_dquote)
		{
			size += get_single_quote_len(&line);
			continue ;
		}
		if (*line == '$' && ft_isenv(*(line + 1)))
		{
			size += get_env_size(&line);
			continue ;
		}
		if (*line == '\"')
			in_dquote = !in_dquote;
		else
			++size;
		++line;
	}
	return (size);
}

int	set_word_token(char **line, t_token **token)
{
	size_t	word_size;

	word_size = get_expanded_size(*line);
	(*token) = gc_malloc(&(g_ms.gcan), sizeof(t_token) + (1 * (word_size + 1)));
	(*token)->next = NULL;
	(*token)->type = WORD;
	if ((*token) == NULL)
		return (LEXER_MALLOC_ERROR);
	return (copy_with_expansion(line, (*token)->value));
}
