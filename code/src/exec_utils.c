/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abentaye <abentaye@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 18:32:36 by abentaye          #+#    #+#             */
/*   Updated: 2024/07/29 08:59:51 by abentaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

int		get_size_list(t_list *list)
{
	t_list	*tmp;
	int		len;

	len = 0;
	tmp = list;
	while(tmp)
	{
		tmp = tmp->next;
		len++;	
	}
	return (len);
}

void	create_args(t_cmd *cmd, t_list	*list)
{
	t_list	*tmp;
	int		count;

	count = 0;
	tmp = list;
	while(tmp)
	{
		cmd->args[count] = tmp->content;
		count++;
		tmp = tmp->next;
	}
	cmd->args[count] = NULL;
	return ;
}

int		check_if_pipe(t_list *list)
{
	t_list	*tmp;
	int 	count;

	count = 0;
	tmp = list;
	while (tmp)
	{
		if (tmp->type == 5)
			count++;
		tmp = tmp->next;	
	}
	return (count);
}
    len_command = 0;
    tmp = list;
    while(tmp)
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