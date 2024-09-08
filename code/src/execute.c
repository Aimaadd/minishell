/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abentaye <abentaye@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 08:54:38 by abentaye          #+#    #+#             */
/*   Updated: 2024/09/08 15:47:12 by abentaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

t_cmd	*setup_execute(t_input *entry, t_env *env_copy)
{
	(void)env_copy;
	entry->cmd = create_cmd(entry);
	if (!entry->cmd)
	{
		printf("Error: command not created\n");
		return (NULL);
	}
	entry->cmd->env_copy = env_copy;
	if (!entry->cmd)
		return (NULL);
	if (init_execute(entry, entry->cmd->env_copy, entry->cmd) == 1)
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
	if (tmp->type == HEREDOC && tmp->next)
		handle_heredoc(tmp->next->content);
	return (0);
}

int	execute(t_input *entry, t_env *env_copy)
{
	entry->cmd = setup_execute(entry, env_copy);
	if (!entry->cmd)
		return (1);
	run_execute(entry->cmd, entry->list);
	if (entry->cmd->next)
		free_command(entry->cmd);
	else
		free(entry->cmd);
	return (0);
}

void	fill_args(char **args, t_list *list, int list_size)
{
	int	i;

	i = 0;
	while (list && i < list_size)
	{
		args[i] = strdup(list->content);
		list = list->next;
		i++;
	}
	args[i] = NULL;
}

char	**list_to_array(t_input *entry)
{
	int		list_size;
	char	**args;

	list_size = get_size_list(entry->list);
	args = malloc((list_size + 1) * sizeof(char *));
	if (!args)
		return (NULL);
	fill_args(args, entry->list, list_size);
	return (args);
}
