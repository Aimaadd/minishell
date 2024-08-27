/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abentaye <abentaye@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 15:36:25 by abentaye          #+#    #+#             */
/*   Updated: 2024/08/27 19:03:19 by abentaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

t_cmd	*ft_new_command(void)
{
	t_cmd	*new;

	new = gc_malloc(&(g_ms->gcmd), sizeof(t_cmd));
	if (!new)
		return (NULL);
	new->envp = NULL;
	new->args = NULL;
	new->env_copy = NULL;
	new->next = NULL;
	new->file = NULL;
	return (new);
}

int	add_command(t_cmd **command)
{
	t_cmd	*new_command;
	t_cmd	*last;

	new_command = ft_new_command();
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
	t_cmd	*command;
	t_list	*tmp;
	int		number_command;

	command = NULL;
	number_command = (get_number_pipe(list) + 1);
	if (number_command != 1)
	{
		if (create_multiple_command(&command, number_command) == 1)
			return (NULL);
	}
	else
	{
		command = ft_new_command();
		if (!command)
			return (NULL);
	}
	tmp = list;
	while (tmp)
	{
		tmp->read = 1;
		tmp = tmp->next;
	}
	return (command);
}
