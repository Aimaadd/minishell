/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abentaye <abentaye@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 15:36:25 by abentaye          #+#    #+#             */
/*   Updated: 2024/08/28 17:13:43 by abentaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

t_cmd	*ft_new_command(t_cmd *cmd)
{
	t_cmd	*new;

	new = gc_malloc(&g_ms->gcmd, sizeof(t_cmd));
	if (!new)
		return (NULL);
	cmd = NULL;
	new->args = NULL;
	new->envp = NULL;
	new->env_copy = NULL;
	new->file = NULL;
	new->type_file = 0;
	new->next = NULL;
	return (new);
}

int	add_command(t_cmd **command)
{
	t_cmd	*new_command;
	t_cmd	*last;

	new_command = ft_new_command(g_ms->cmd);
	if (!new_command)
		return (1);
	if (*command == NULL)
	{
		*command = new_command;
		return (0);
	}
	last = *command;
	while (last->next)
		last = last->next;
	last->next = new_command;
	return (0);
}

int	create_multiple_command(t_cmd **command, int number_command)
{
	int		count_command;

	count_command = 0;
	while (count_command != number_command)
	{
		if (add_command(command) == 1)
			return (1);
		count_command++;
	}
	return (0);
}

t_cmd	*create_cmd(t_list *list)
{
	t_list	*tmp;
	int		number_command;

	number_command = (get_number_pipe(list) + 1);
	if (number_command != 1)
	{	
		if (create_multiple_command(&g_ms->cmd, number_command) == 1)
			return (NULL);
	}
	else
	{
		g_ms->cmd = ft_new_command(g_ms->cmd);
		if (!g_ms->cmd)
			return (NULL);
	}
	tmp = list;
	while (tmp)
	{
		tmp->read = 1;
		tmp = tmp->next;
	}
	return (g_ms->cmd);
}
