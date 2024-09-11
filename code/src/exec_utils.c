/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abentaye <abentaye@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 18:32:36 by abentaye          #+#    #+#             */
/*   Updated: 2024/09/11 18:39:18 by abentaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

int	get_number_pipe(t_list *list)
{
	int		count_pipe;
	t_list	*tmp;

	count_pipe = 0;
	tmp = list;
	while (tmp)
	{
		if (tmp->type == PIPE)
			count_pipe++;
		tmp = tmp->next;
	}
	return (count_pipe);
}

int	get_size_command(t_list *list)
{
	int		len_command;
	t_list	*tmp;

	len_command = 0;
	tmp = list;
	while (tmp)
	{
		if (tmp->read == 0)
			tmp = tmp->next;
		else
		{
			if (tmp->type == PIPE)
			{
				tmp->read = 0;
				return (len_command);
			}
			len_command++;
			tmp->read = 0;
			tmp = tmp->next;
		}
	}
	return (len_command);
}
