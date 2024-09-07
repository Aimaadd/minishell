/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abentaye <abentaye@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 14:14:33 by abentaye          #+#    #+#             */
/*   Updated: 2024/09/07 14:21:00 by abentaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

void	create_node_from_quotes(char *line, int first_quote, int second_quote
	, t_list **list)
{
	char	*content;

	content = strndup(line + first_quote + 1, second_quote - first_quote - 1);
	new_node(list, content);
}

int	find_next_quote(char *line, int start_index)
{
	while (line[start_index])
	{
		if (line[start_index] == '\'' || line[start_index] == '\"')
			return (start_index);
		start_index++;
	}
	return (-1);
}

t_list	*sort_quotes(char *line)
{
	int		first_quote;
	int		second_quote;
	int		quotes_counter;
	t_list	*list;

	list = NULL;
	quotes_counter = counting_quotes(line);
	if (quotes_counter % 2 != 0)
		return (NULL);
	first_quote = find_next_quote(line, 0);
	while (first_quote != -1)
	{
		second_quote = find_next_quote(line, first_quote + 1);
		if (second_quote == -1)
			break ;
		create_node_from_quotes(line, first_quote, second_quote, &list);
		first_quote = find_next_quote(line, second_quote + 1);
	}
	return (list);
}

int	counting_quotes(char *line)
{
	int	i;
	int	quotes_counter;

	quotes_counter = 0;
	i = 0;
	while (line[i])
	{
		if (line[i] == '\'' || line[i] == '\"')
			quotes_counter++;
		i++;
	}
	return (quotes_counter);
}
