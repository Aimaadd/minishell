/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abentaye <abentaye@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 08:54:38 by abentaye          #+#    #+#             */
/*   Updated: 2024/08/14 14:48:23 by abentaye         ###   ########.fr       */
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

// void	printab(char **str)
// {
// 	int	i;

// 	i = -1;
// 	while (str[++i])
// 		printf("%s\n", str[i]);
// 	return ;
// }

// void	ft_printlst(t_cmd *cmd)
// {
// 	t_cmd	*tmp;

// 	tmp = cmd;
// 	while (tmp)
// 	{
// 		printab(tmp->args);
// 		tmp = tmp->next;
// 	}
// 	return ;
// }

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

int	execute(t_input *entry, t_env *env_copy)
{
	t_cmd	*command;
	
	command = setup_execute(entry, env_copy);
	if (!command)
		return (1);
	run_execute(command, entry->list);
	free_command(command);
	return (0);
}
