/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abentaye <abentaye@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 16:28:06 by abentaye          #+#    #+#             */
/*   Updated: 2024/09/15 12:50:02 by abentaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_minishell	g_ms;

int	event(void)
{
	return (0);
}

static int	init_minishell(char **env)
{
	g_ms.status = STATUS_IDLE;
	g_ms.bad_token = NULL;
	g_ms.token = NULL;
	g_ms.old_status = 0;
	gc_init(&(g_ms.gcan));
	gc_init(&(g_ms.gcenv));
	setup_sigactions();
	if (get_env_copy(env))
		return (1);
	rl_event_hook = event;
	return (0);
}

void	print_error(char *msg_a, char *msg_b, char *msg_c)
{
	ft_putstr_fd(msg_a, STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	ft_putstr_fd(msg_b, STDERR_FILENO);
	if (msg_c == NULL)
	{
		ft_putstr_fd("\n", STDERR_FILENO);
		return ;
	}
	ft_putstr_fd(": ", STDERR_FILENO);
	ft_putstr_fd(msg_c, STDERR_FILENO);
	ft_putstr_fd("\n", STDERR_FILENO);
}

int	main(int argc, char **argv, char **env)
{
	(void)argc;
	(void)argv;
	signal(SIGQUIT, SIG_IGN);
	if (init_minishell(env))
	{
		print_error("minishell", "internal error", strerror(errno));
		return (1);
	}
	interpret_loop();
	gc_clean(&(g_ms.gcan));
	gc_clean(&(g_ms.gcenv));
	return (g_ms.old_status);
}
