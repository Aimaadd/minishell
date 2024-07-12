/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt_handling.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abentaye <abentaye@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 12:54:11 by abentaye          #+#    #+#             */
/*   Updated: 2024/07/12 20:12:13 by abentaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

void	prompt_handler(t_input *entry)
{
	entry->line = readline("minishell$ ");
	printf("TESO OU?");
	add_history(entry->line);
	if (entry->line == NULL)
		exit(1);
}
