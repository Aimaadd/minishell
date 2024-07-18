/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abentaye <abentaye@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 08:54:38 by abentaye          #+#    #+#             */
/*   Updated: 2024/07/17 18:08:30 by mmeerber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"



void	setup_execute(t_input *entry, t_env *env_copy)
{
	t_cmd	*command;
	(void)env_copy;
	command = create_cmd(entry->list);
}

int		execute(t_input *entry, t_env *env_copy)
{
	(void)entry;
	(void)env_copy;

	setup_execute(entry, env_copy);
	return (0);
}
