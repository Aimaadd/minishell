/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abentaye <abentaye@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 17:19:03 by abentaye          #+#    #+#             */
/*   Updated: 2024/09/15 12:45:44 by abentaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	echo_builtin(int argc, char **argv)
{
	int		flag;
	int		i;

	i = 1;
	flag = 0;
	while (i < argc && !ft_strncmp(argv[i], "-n", 3))
	{
		flag = 1;
		++i;
	}
	while (i < argc)
	{
		ft_putstr_fd(argv[i], STDOUT_FILENO);
		if (i < (argc - 1))
			ft_putstr_fd(" ", STDOUT_FILENO);
		++i;
	}
	if (!flag)
		ft_putstr_fd("\n", STDOUT_FILENO);
	return (0);
}
