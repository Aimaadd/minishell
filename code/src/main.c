/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abentaye <abentaye@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 17:41:56 by abentaye          #+#    #+#             */
/*   Updated: 2024/08/02 15:18:11 by abentaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

void	minishell_loop(t_input *entry, t_env *env_copy)
{
	t_list	*tmp;

	while (1)
	{
		entry->line = prompt_handler(entry->line);
		input_to_list(entry);
		if (read_list(entry->list) == ERROR_LOOP)
			continue ;
		entry->signal = execute(entry, env_copy);
		if (entry->signal == 1)
			exit(1);
		free(entry->line);
		while (entry->list)
		{
			tmp = entry->list;
			entry->list = entry->list->next;
			while (tmp)
			{
				tmp = tmp->next;
			}
			free(tmp);
		}
	}
}

int	main(int ac, char **ag, char **envp)
{
	t_env				*env_copy;
	t_input				*entry;
	struct sigaction	sa;

	memset(&sa, 0, sizeof(sa));
	entry = NULL;
	(void)ac;
	(void)ag;
	entry = init_input();
	sa.sa_handler = init_signal(entry);
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	env_copy = create_copy_env(envp);
	minishell_loop(entry, env_copy);
	return (0);
}
