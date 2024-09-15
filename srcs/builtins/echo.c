/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abentaye <abentaye@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 17:19:03 by abentaye          #+#    #+#             */
/*   Updated: 2024/09/15 15:48:20 by abentaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

// int	check_parameter(char **args)
// {
// 	int		i;

// 	i = 1;
// 	if (!args || !args[1])
// 		return (1);
// 	if (args[1][0] == '-')
// 	{
// 		while (args[1][i])
// 		{
// 			if (args[1][i] != 'n')
// 				return (0);
// 			i++;
// 		}
// 		return (1);
// 	}
// 	return (0);
// }

// int	echo_builtin(int argc, char **argv)
// {
// 	int		flag;
// 	int		i;

// 	i = 2;
// 	flag = check_parameter(argv);
// 	while (i < argc - 1)
// 	{
// 		ft_putstr_fd(argv[i], STDOUT_FILENO);
// 		ft_putstr_fd(" ", STDOUT_FILENO);
// 		++i;
// 	}
// 	ft_putstr_fd(argv[i], STDOUT_FILENO);
// 	if (!flag)
// 		ft_putstr_fd("\n", STDOUT_FILENO);
// 	return (0);
// }

int    echo_builtin(int argc, char **argv)
{
	int        flag;
	int        i;

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