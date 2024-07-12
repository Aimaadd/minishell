/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abentaye <abentaye@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 17:41:56 by abentaye          #+#    #+#             */
/*   Updated: 2024/07/12 18:58:38 by abentaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

void	minishell_loop(t_input *entry, t_env *env_copy)
{
	(void)env_copy;

	init_input(entry);
	while (1)
	{
		entry->line = prompt_handler();
		printf("entry -> line = %s\n", entry->line);
		input_to_list(entry);
		while (entry->list)
		{
			// printf("tmp printing = %s\n", tmp->content);
			entry->list = entry->list->next;
		}
		if (!entry->list)
		{
			printf("noob \n");
			return ;
		}
		if (entry->list)
			// read_list(entry->list);
		execute(entry, env_copy);
		free(entry->line);
		while (entry->list)
		{
			entry->list = entry->list->next;
		}
	}
}

int	main(int ac, char **ag, char **envp)
{
	t_env	*env_copy;
	env_copy = create_copy_env(envp);
	t_input	entry;

	(void)ac;
	(void)ag;
	init_input(&entry);
	init_signal();
	env_copy = create_copy_env(envp);
	minishell_loop(&entry, env_copy);
	return (0);
}