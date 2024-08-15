/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abentaye <abentaye@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 15:31:53 by abentaye          #+#    #+#             */
/*   Updated: 2024/08/14 15:36:54 by abentaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

int	check_parameter(char **args)
{
	char	**tmp;
	int		i;

	i = 1;
	tmp = args;
	if (!tmp || !tmp[1])
		return (1);
	while (tmp[1][i])
	{
		if (tmp[1][i] == 'n')
			i++;
		else
			return (0);
	}
	return (1);
}

void	write_args(int x, int y, char **args)
{
	while (args[x][y])
	{
		write(1, &args[x][y], 1);
		y++;
	}
	if (args[x + 1])
		write(1, " ", 1);
	x++;
}

void	ft_echo(t_cmd *command)
{
	int		flag;
	int		x;
	int		y;
	char	**args;

	args = command->args;
	flag = 0;
	x = 0;
	y = 0;
	if (!args[1])
		write(1, "\n", 1);
	if (check_parameter(args) == 0)
		flag = 1;
	if (flag == 0)
		x = 2;
	else
		x = 1;
	while (args[x])
	{
		y = 0;
		write_args(x++, y, args);
	}
	if (flag == 1)
		write(1, "\n", 1);
}		
