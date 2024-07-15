/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abentaye <abentaye@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 17:41:56 by abentaye          #+#    #+#             */
/*   Updated: 2024/07/15 15:57:21 by mmeerber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

void	minishell_loop(t_input *entry, t_env *env_copy)
{
	t_list	*tmp;
	int		signal;

	while (1)
	{
		entry->line = prompt_handler(entry->line);
		input_to_list(entry);
		read_list(entry->list);
		//in execute(entry, env_copy) : signal_assignement ($?)
		signal = execute(entry, env_copy);
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
	t_env				*env_copy;
	t_input				*entry;
	struct sigaction	sa;

	memset(&sa, 0, sizeof(sa));
	env_copy = create_copy_env(envp);
	entry = NULL;
	(void)ac;
	(void)ag;
	entry = init_input();
	sa.sa_handler = init_signal();
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	env_copy = create_copy_env(envp);
	minishell_loop(entry, env_copy);
	return (0);
}
