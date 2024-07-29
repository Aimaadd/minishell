/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abentaye <abentaye@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 03:09:59 by abentaye          #+#    #+#             */
/*   Updated: 2024/07/29 10:58:35 by abentaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

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
	{
		printf("syntax error : quotes not closed\n");
		return (printf("syntax error : quotes not closed\n"), UNCLOSED_QTS);
	}
	return (quotes_counter);
}

//This function will read the content of a node and return the type of the content
int	read_type(char *content)
{
	if (!ft_strncmp(content, "|", ft_strlen(content)))
		return (PIPE);
	else if (!ft_strncmp(content, ">", ft_strlen(content)))
		return (REDIRECTION);
	else if (!ft_strncmp(content, "$", 1))
		return (ENV);
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
	if (list->type == REDIRECTION)
		redirection(list);
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
		list->type = read_type(list->content);
		if (contains_quotes(list) == UNCLOSED_QTS)
			return (ERROR_LOOP);
		if_type(list);
		list = list->next;
	}
	return (0);
}

int	is_parameter(const char *str)
{
	int	i;

	if (str[0] == '-' && str[1])
	{
		i = 1;
		while (str[i])
		{
			if (str[i] == ' ')
				return (1);
			i++;
		}
		return (0);
	}
	return (1);
}
