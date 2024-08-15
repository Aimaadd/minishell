/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abentaye <abentaye@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 08:54:38 by abentaye          #+#    #+#             */
/*   Updated: 2024/08/16 00:04:17 by abentaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

t_cmd	*setup_execute(t_input *entry)
{
	entry->cmd = create_cmd(entry->list);
	printlist(entry->list);
	if (!entry->cmd)
		return (NULL);
	if (init_execute(entry) == 1)
		return (NULL);
	return (entry->cmd);
}

int	run_execute(t_cmd *command, t_list *list)
{
	t_list	*tmp;

	tmp = list;
	if (!command->next)
		simple_command(command);
	else
		multiple_command(command);
	if (tmp->type == HEREDOC)
		handle_heredoc(tmp->next->content);
	return (0);
}

int	execute(t_input *entry)
{
	entry->cmd = setup_execute(entry);
	if (!entry->cmd)
		return (1);
	entry->cmd->args = fill_array_from_list(entry->list);
	// printab(entry->cmd->args);
	run_execute(entry->cmd, entry->list);
	if (entry->cmd->next)
		free_command(entry->cmd);
	else
		free(entry->cmd);
	return (0);
}
