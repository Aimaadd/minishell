/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abentaye <abentaye@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 17:41:56 by abentaye          #+#    #+#             */
/*   Updated: 2024/05/31 00:56:09 by abentaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

int	main(void)
{
	t_input	entry;
	t_list  *tmp;

	init_input(&entry);
	while (1)
	{
		entry.line = readline("minishell$ ");
		if (!entry.line)
			break ;
		input_to_list(&entry);
		tmp = entry.list;
		read_list(tmp);
		while (entry.list)
		{
			free(entry.list->content);
			entry.list = entry.list->next;
		}
	}
	return (0);
}
