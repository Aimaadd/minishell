/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abentaye <abentaye@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 08:54:38 by abentaye          #+#    #+#             */
/*   Updated: 2024/08/29 18:23:44 by abentaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

void	*setup_execute(void)
{
	g_ms->cmd = create_cmd(g_ms->list);
	if (!g_ms->cmd)
		return (NULL);
	return (NULL);
}

int	run_execute(t_list *list)
{
	t_list	*tmp;

	tmp = list;
	if (!g_ms->cmd->next)
		simple_command(g_ms->cmd); // to keep
	else
	{
		multiple_command(g_ms->cmd);
	}
	if (tmp->type == HEREDOC)
		handle_heredoc(tmp->next->content);
	return (0);
}

int	execute(void)
{
	setup_execute();
	if (!g_ms->cmd)
		return (1);
	g_ms->cmd->args = fill_array_from_list(g_ms->list);
	g_ms->cmd->envp = fill_array_from_env(g_ms->cmd->env_copy);
	get_number_command(g_ms->cmd);
	run_execute(g_ms->list);
	// if (g_ms->cmd->next)
	// 	free_command(g_ms->cmd);
	// free(g_ms->cmd);
	return (0);
}
