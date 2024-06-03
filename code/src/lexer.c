/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abentaye <abentaye@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 03:09:59 by abentaye          #+#    #+#             */
/*   Updated: 2024/05/31 15:33:38 by abentaye         ###   ########.fr       */
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
	else if (!ft_strncmp(content, "$", ft_strlen(content)))
		return (PARAMETER);
	else if (!ft_strncmp(content, " ", ft_strlen(content)))
		return (ARGUMENT);
	return (0);
}


// this function will read the content of the list and give the type of each
// element in the list 
int	read_list(t_list *list)
{
	while (list)
	{	
		list->type = read_type(list->content);
		printf("content : %s | type : %d\n",list->content, list->type);
		list = list->next;
	}
	return (0);
}
