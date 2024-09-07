/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abentaye <abentaye@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 19:09:08 by abentaye          #+#    #+#             */
/*   Updated: 2024/09/07 20:09:58 by abentaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

int	add_args_bis(t_list **tmp_list, t_cmd **tmp_cmd)
{
	if ((*tmp_list)->type == PIPE)
	{
		(*tmp_list)->second_read = 0;
		return (0);
	}
	if ((*tmp_list)->type == REDIRECTION || (*tmp_list)->type == APPEND)
	{
		if ((*tmp_list)->type == REDIRECTION)
			(*tmp_cmd)->type_file = 1;
		else
			(*tmp_cmd)->type_file = 2;
		(*tmp_cmd)->file = (*tmp_list)->next->content;
		(*tmp_list)->second_read = 0;
		if (!(*tmp_list)->next->next)
			return (0);
		(*tmp_list) = (*tmp_list)->next;
		(*tmp_list)->second_read = 0;
		(*tmp_list) = (*tmp_list)->next;
	}
	return (1);
}

int	add_args_sub_loop(t_list **tmp_list, t_cmd **tmp_cmd, int *x)
{
	while ((*tmp_list))
	{
		if ((*tmp_list)->second_read == 0)
			(*tmp_list) = (*tmp_list)->next;
		else
		{
			if (!add_args_bis(tmp_list, tmp_cmd))
				break ;
			(*tmp_cmd)->args[*x] = malloc(sizeof(char)
					* (ft_strlen((*tmp_list)->content) + 1));
			if (!(*tmp_cmd)->args[*x])
				return (1);
			ft_strlcpy((*tmp_cmd)->args[*x], (*tmp_list)->content,
				(ft_strlen((*tmp_list)->content) + 1));
			(*tmp_list)->second_read = 0;
			(*tmp_list) = (*tmp_list)->next;
			(*x)++;
		}
	}
	return (0);
}

int	add_args(t_cmd *command, t_list *list)
{
	t_list	*tmp_list;
	t_cmd	*tmp_cmd;
	int		len_command;
	int		x;

	tmp_list = list;
	tmp_cmd = command;
	while (tmp_cmd)
	{
		x = 0;
		len_command = get_size_command(tmp_list);
		tmp_cmd->args = malloc(sizeof(char *) * (len_command + 1));
		if (!tmp_cmd->args)
			return (1);
		if (add_args_sub_loop(&tmp_list, &tmp_cmd, &x))
			return (1);
		tmp_cmd->args[x] = NULL;
		tmp_cmd = tmp_cmd->next;
	}
	return (0);
}
