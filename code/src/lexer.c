/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abentaye <abentaye@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 03:09:59 by abentaye          #+#    #+#             */
/*   Updated: 2024/09/05 14:41:20 by abentaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

char	*remove_quotes(char *content)
{
	int		i;
	int		j;
	int		len;
	char	*result;

	len = strlen(content);
	result = malloc(len + 1);
	if (!result)
		return (NULL);
	i = 0;
	if (len < 2)
		return (content);
	j = 0;
	while (i < len)
	{
		if (content[i] != '\"' && content[i] != '\'')
			result[j++] = content[i];
		i++;
	}
	result[j] = '\0';
	return (result);
}

int	contains_quotes(t_list *list)
{
	int	i;
	int	quotes_counter;

	quotes_counter = 0;
	while (list)
	{
		if (!list->content)
			return (1);
		i = 0;
		while (list->content[i])
		{
			if (list->content[i] == '\"' || list->content[i] == '\'')
				quotes_counter++;
			i++;
		}
		list = list->next;
	}
	if (quotes_counter % 2 != 0)
		return (printf("syntax error : quotes not closed\n"), UNCLOSED_QTS);
	return (quotes_counter);
}

int	read_type(char *content)
{
	if (!ft_strncmp(content, "|", 1))
		return (PIPE);
	else if (!ft_strncmp(content, ">>", 2))
		return (APPEND);
	else if (!ft_strncmp(content, ">", 1))
		return (REDIRECTION);
	else if (!ft_strncmp(content, "<<", 2))
		return (HEREDOC);
	else if (!ft_strncmp(content, "$", 1))
		return (ENV);
	else if (!ft_strncmp(content, "<", 1))
		return (INFILE);
	else if (!is_parameter(content))
		return (PARAMETER);
	else if (!ft_strncmp(content, " ", ft_strlen(content)))
		return (ARGUMENT);
	else
		return (BINARY);
	return (0);
}

int	if_type(t_list *list)
{
	if (list->type == ENV)
		to_expand(list);
	return (list->type);
}

// this function will read the content of the list and give the type of each
// element in the list 
int	read_list(t_list *list)
{
	if (!list)
		return (ERROR_LOOP);
	while (list)
	{
		list->content = remove_quotes(list->content);
		list->type = read_type(list->content);
		if (contains_quotes(list) == UNCLOSED_QTS)
			return (ERROR_LOOP);
		if (list->type != REDIRECTION && list->type != PIPE
			&& list->type != OUTFILE && list->type != APPEND && list->type
			!= INFILE)
			list->content = remove_quotes(list->content);
		if_type(list);
		list = list->next;
	}
	return (0);
}
