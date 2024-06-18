/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abentaye <abentaye@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 11:16:36 by abentaye          #+#    #+#             */
/*   Updated: 2024/06/18 10:45:57 by abentaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

void	signal_handler(int signum)
{
	if (signum == SIGINT)
	{	
		write(1, "get cancer\n", 11);
		exit(1);
	}
	else if (signum == SIGQUIT)
	{
		write(1, "get cancer\n", 11);
		exit(1);
	}
	else
	{
		write(1, "get cancer\n", 11);
		exit(1);
	}
}

void init_signal(void)
{
	sigset_t	set;
	sigemptyset(&set);
	signal(SIGQUIT, signal_handler);
	signal(SIGINT, signal_handler);
	signal(SIGTSTP, signal_handler);
	
}
