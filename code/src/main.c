/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abentaye <abentaye@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 17:41:56 by abentaye          #+#    #+#             */
/*   Updated: 2024/06/13 13:24:23 by abentaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"



int	main(int ac, char **ag, char **envp)
{
	t_env	*env_copy;
	env_copy = create_copy_env(envp);
	t_input	entry;
	t_list	*tmp;
	int	pid;

	pid = getpid();
	init_input(&entry);
	env_copy = create_copy_env(envp);
	printf("minishell PID: %d\n", pid);	
	while (1)
	{
		entry.line = prompt_handler();
		if (!entry.line)
			continue ;
		input_to_list(&entry);
		tmp = entry.list;
		execute(&entry, env_copy);
	}
	return (0);
}
