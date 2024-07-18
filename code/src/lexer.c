/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abentaye <abentaye@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 03:09:59 by abentaye          #+#    #+#             */
/*   Updated: 2024/07/14 18:19:15 by abentaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

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

// this function will read the content of the list and give the type of each
// element in the list 
int	read_list(t_list *list)
{
	while (list)
	{
		list->type = read_type(list->content);
		if (list->type == ENV)
		{
			to_expand(list);
			printf("content to expand : %s , type : %d\n", list->content, list->type);
		}
		// printf("content : %s | type : %d\n",list->content, list->type);
		list = list->next;
	}
	return (0);
}

// int read_list(t_list *list)
// {
// 	t_list *current;
	
// 	current = list;
// 	while (current)
// 	{
// 		printf("%s\n", current->content); 
// 		current = current->next;
// 	}
// 	return (0);
// }


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
