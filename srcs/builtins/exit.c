/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abentaye <abentaye@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 17:39:31 by abentaye          #+#    #+#             */
/*   Updated: 2024/09/15 13:36:18 by abentaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	exit_builtin(char **argv)
{
	int	i;

	kill_all_childs(SIGKILL);
	wait_all_childs();
	i = 0;
	if (argv[1])
	{
		while (ft_isdigit(argv[1][i]))
			i++;
		if (!argv[1][i])
			exit(ft_atoi(argv[1]));
		else
			exit (1);
	}
	gc_clean(&(g_ms.gcan));
	gc_clean(&(g_ms.gcenv));
	exit(0);
}
