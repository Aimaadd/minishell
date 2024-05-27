/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abentaye <abentaye@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 03:09:59 by abentaye          #+#    #+#             */
/*   Updated: 2024/05/27 12:17:19 by abentaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

// this function will read the content of the list and give the type of each
// element in the list 
int	read_list(t_list *list)
{
	while (list)
	{
		if (list->content[0] == '|')
			list->type = PIPE;
		else if (list->content[0] == '>')
			list->type = REDIRECTION;
		else if (list->content[0] == '$')
			list->type = PARAMETER;
		else
			list->type = BINARY;
	}
	return (0);
}
