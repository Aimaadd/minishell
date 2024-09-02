/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abentaye <abentaye@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 15:29:33 by abentaye          #+#    #+#             */
/*   Updated: 2024/08/29 22:53:39 by abentaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

int	add_envp(t_cmd *command, t_env *env_copy)
{
	t_cmd	*tmp;

	tmp = command;
	while (tmp)
	{
		tmp->envp = conv_tab_env(env_copy);
		tmp->env_copy = env_copy;
		if (!tmp->envp)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

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

int	add_args_sub_loop(t_list **tmp_list, t_cmd **tmp_cmd)
{
	int x;

	x = 0;
	while ((*tmp_list))
	{
		if ((*tmp_list)->second_read == 0)
			(*tmp_list) = (*tmp_list)->next;
		else
		{
			if (!add_args_bis(tmp_list, tmp_cmd))
				break ;
			(*tmp_cmd)->args[x] = ft_strdup((*tmp_list)->content);
			(*tmp_list)->second_read = 0;
			(*tmp_list) = (*tmp_list)->next;
			x++;
		}
	}
	(*tmp_cmd)->args[x] = NULL;
	return (0);
}

int	add_args(t_cmd	*command, t_list *list)
{
	t_list	*tmp_list;
	t_cmd	*tmp_cmd;
	int		len_command;

	tmp_list = list;
	tmp_cmd = command;
	while (tmp_cmd)
	{
		len_command = get_size_command(tmp_list);
		tmp_cmd->args = malloc(sizeof(char *) * (len_command + 1));
		if (!tmp_cmd->args)
			return (1);
		if (add_args_sub_loop(&tmp_list, &tmp_cmd))
			return (1);
		tmp_cmd = tmp_cmd->next;
	}
	return (0);
}

int	init_execute(t_input *entry, t_env *env_copy, t_cmd *command)
{
	if (add_envp(command, env_copy) == 1)
		return (1);
	if (add_args(command, entry->list) == 1)
		return (1);
	return (0);
}
