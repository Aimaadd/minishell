/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abentaye <abentaye@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 08:54:38 by abentaye          #+#    #+#             */
/*   Updated: 2024/08/27 19:14:25 by abentaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

t_cmd	*setup_execute(void)
{
	g_ms->cmd = create_cmd(g_ms->list);
	if (!g_ms->cmd)
		return (NULL);
	return (g_ms->cmd);
}

int	run_execute(t_cmd *command, t_list *list)
{
	t_list	*tmp;

	tmp = list;
	if (!command->next)
		simple_command(command); // to keep
	else
		multiple_command(command);
	if (tmp->type == HEREDOC)
		handle_heredoc(tmp->next->content);
	return (0);
}

int	execute(void)
{
	g_ms->cmd = setup_execute();
	if (!g_ms->cmd)
		return (1);
	g_ms->cmd->args = fill_array_from_list(g_ms->list);
	g_ms->cmd->envp = fill_array_from_env(g_ms->cmd->env_copy);
	run_execute(g_ms->cmd, g_ms->list);
	if (g_ms->cmd->next)
		free_command(g_ms->cmd);
	// else
	// 	free(g_ms->cmd);
	return (0);
}
