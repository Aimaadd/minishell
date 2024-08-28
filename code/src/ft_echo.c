/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abentaye <abentaye@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 15:31:53 by abentaye          #+#    #+#             */
/*   Updated: 2024/08/28 14:54:48 by abentaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

int	check_parameter(char **args)
{
	int		i;

	i = 1;
	if (!args || !args[1])
		return (1);
	if (args[1][0] == '-')
	{
		while (args[1][i])
		{
			if (args[1][i] != 'n')
				return (0);
			i++;
		}
		return (1);
	}
	return (0);
}

void	write_args(int x, char **args)
{
	int	y;

	while (args[x])
	{
		y = 0;
		while (args[x][y])
		{
			write(1, &args[x][y], 1);
			y++;
		}
		if (args[x + 1])
			write(1, " ", 1);
		x++;
	}
}

void	ft_echo(t_cmd *command)
{
	int		flag;
	int		x;
	char	**args;

	args = command->args;
	if (!args[1])
	{
		write(1, "\n", 1);
		return ;
	}
	flag = check_parameter(args);
	if (flag == 1)
		x = 2;
	else
		x = 1;
	write_args(x, args);
	if (flag == 0)
		write(1, "\n", 1);
}
