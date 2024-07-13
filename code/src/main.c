/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abentaye <abentaye@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 17:41:56 by abentaye          #+#    #+#             */
/*   Updated: 2024/07/13 17:12:54 by mmeerber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

void	minishell_loop(t_input *entry, t_env *env_copy)
{
	t_list	*tmp;

	while (1)
	{
		entry->line = prompt_handler(entry->line);
		input_to_list(entry, entry->line);
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
	t_env	*env_copy;
	t_input	*entry;

	env_copy = create_copy_env(envp);
	entry = NULL;
	(void)ac;
	(void)ag;
	entry = init_input();
	init_signal();
	env_copy = create_copy_env(envp);
	minishell_loop(entry, env_copy);
	return (0);
}
