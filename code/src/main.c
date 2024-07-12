/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abentaye <abentaye@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 17:41:56 by abentaye          #+#    #+#             */
/*   Updated: 2024/07/12 14:00:42 by abentaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

void	minishell_loop(t_input *entry, t_env *env_copy)
{
	t_list	*tmp;

	while (1)
	{
		entry->line = prompt_handler();
		if (!entry->line)
			continue ;
		input_to_list(entry);
		tmp = entry->list;
		read_list(entry->list);
		execute(entry, env_copy);
		free(entry->line);
		while (entry->list)
		{
			tmp = entry->list;
			entry->list = entry->list->next;
			free(tmp->content);
			free(tmp);
		}
	}
}

int	main(int ac, char **ag, char **envp)
{
	(void)ac;
	(void)ag;
	t_env	*env_copy;
	env_copy = create_copy_env(envp);
	t_input	entry;

	init_input(&entry);
	init_signal();
	env_copy = create_copy_env(envp);
	minishell_loop(&entry, env_copy);
	return (0);
}