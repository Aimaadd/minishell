/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abentaye <abentaye@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 18:39:35 by abentaye          #+#    #+#             */
/*   Updated: 2024/09/15 18:39:37 by abentaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	clean_exit(int err)
{
	gc_clean(&(g_ms.gcan));
	gc_clean(&(g_ms.gcenv));
	exit(err);
}

void	hardfail_exit(int lerrno)
{
	ft_putstr_fd("minishell: internal error: ", STDERR_FILENO);
	ft_putstr_fd(strerror(lerrno), STDERR_FILENO);
	ft_putstr_fd("\n", STDERR_FILENO);
	kill_all_childs(SIGKILL);
	wait_all_childs();
	clean_exit(lerrno);
}
