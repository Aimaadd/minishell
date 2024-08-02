/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abentaye <abentaye@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 15:31:53 by abentaye          #+#    #+#             */
/*   Updated: 2024/08/02 15:31:59 by abentaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

int	check_parametre(char **args)
{
	char	**tmp;

	tmp = args;
	if (!tmp)
		printf("bail");
	if (ft_strncmp(tmp[1], "-n", check_max_len(tmp[1], "-n")) == 0)
		return (0);
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
	if (check_parametre(command->args) == 1)
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
		write(1, "\n", 2);
}
