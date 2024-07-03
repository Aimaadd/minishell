/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abentaye <abentaye@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 11:16:36 by abentaye          #+#    #+#             */
/*   Updated: 2024/06/28 16:57:44 by abentaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

void	signal_handler(int signum, t_input *entry, t_env *env_copy)
{
	if (signum == SIGINT)
	{
		//free + init to restart fresh minishell vars..
	}
	else if (signum == SIGQUIT)
		return ;
	else
		exit(1);
}

void init_signal(t_input *entry, t_env *env_copy)
{
	sigset_t	set;
	sigemptyset(&set);
	signal(SIGQUIT, signal_handler);
	signal(SIGINT, signal_handler);
	signal(SIGTSTP, signal_handler);
	
}
