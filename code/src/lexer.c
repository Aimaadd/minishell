/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abentaye <abentaye@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 03:09:59 by abentaye          #+#    #+#             */
/*   Updated: 2024/05/30 18:00:02 by abentaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

// this function will read the content of the list and give the type of each
// element in the list 
int	read_list(t_list *list)
{
	int i;

	while (list)
	{	
		i = 0;
		while(list->content[i])
		{
			if (list->content[i] == '|')
				list->type = PIPE;
			else if (list->content[i] == '>')
				list->type = REDIRECTION;
			else if (list->content[i] == '$')
				list->type = PARAMETER;
			else
				list->type = BINARY;
			// printf("content : %s type : %d\n",list->content, list->type);
			i++;
		}
		list = list->next;
	}
	return (0);
}
