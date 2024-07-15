/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abentaye <abentaye@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 11:16:36 by abentaye          #+#    #+#             */
/*   Updated: 2024/07/15 19:17:32 by abentaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

void	signal_handler(int signum)
{
	if (signum == SIGINT)
	{
		rl_replace_line("", 0);
		printf("\n");
		rl_on_new_line();
		rl_redisplay();
	}
	else if (signum == SIGQUIT)
		exit(0);
	else
		exit(0);
}

void	*init_signal(t_input *entry)
{
	sigset_t			set;

	sigemptyset(&set);
	if (signal(SIGQUIT, signal_handler))
		entry->signal = 128 + SIGINT;
	if (signal(SIGINT, signal_handler))
		entry->signal = 128 + SIGINT;
	if (signal(SIGTSTP, signal_handler))
		entry->signal = 128 + SIGTSTP;
	return (NULL);
}

// int	signal_assignement(t_input *entry)
// {

// 	entry->signal = 
// }