/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abentaye <abentaye@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 17:41:56 by abentaye          #+#    #+#             */
/*   Updated: 2024/08/16 23:58:59 by abentaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

t_input	*g_ms;

int	minishell_loop(void)
{
	t_list	*tmp;

	while (1)
	{
		g_ms->line = prompt_handler(g_ms->line);
		input_to_list();
		if (read_list(g_ms->list) == ERROR_LOOP)
			continue ;
		execute();
		free(g_ms->line);
		while (g_ms->list)
		{
			tmp = g_ms->list;
			g_ms->list = g_ms->list->next;
			while (tmp)
				tmp = tmp->next;
			free(tmp);
		}
	}
	return (g_ms->ret_val);
}

int	main(int ac, char **ag, char **envp)
{
	struct sigaction	sa;

	memset(&sa, 0, sizeof(sa));
	g_ms = NULL;
	(void)ac;
	(void)ag;
	g_ms = init_input();
	sa.sa_handler = init_signal();
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	g_ms->env = create_copy_env(envp);
	if (!g_ms->env)
		perror("g_ms vide");
	return (minishell_loop());
}
