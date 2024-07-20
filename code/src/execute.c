/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abentaye <abentaye@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 08:54:38 by abentaye          #+#    #+#             */
/*   Updated: 2024/07/20 19:00:51 by mmeerber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

t_cmd	*setup_execute(t_input *entry, t_env *env_copy)
{
	t_cmd	*command;
	(void)env_copy;
	command = create_cmd(entry->list);
	if (!command)
		return (NULL);
	if (init_execute(entry, env_copy, command) == 1)
		return (NULL);
	return (command);
}

int		run_execute(t_cmd *command)
{
	if (!command->next)
		simple_command(command);
	else
		multiple_command(command);
	return (0);
}

int		execute(t_input *entry, t_env *env_copy)
{
	t_cmd	*command;

	command = setup_execute(entry, env_copy);
	if (!command)
		return (1);
	run_execute(command);
	return (0);
}
