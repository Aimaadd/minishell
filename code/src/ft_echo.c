/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abentaye <abentaye@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 15:31:53 by abentaye          #+#    #+#             */
/*   Updated: 2024/09/07 18:06:42 by abentaye         ###   ########.fr       */
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
	x++;
}

int	is_empty_or_space(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}

int	is_only_spaces(char *str)
{
	while (*str)
	{
		if (*str != ' ')
			return (0);
		str++;
	}
	return (1);
}

void	ft_echo(t_cmd *command)
{
	int		flag;
	int		x;
	char	**args;

	args = command->args;
	flag = 0;
	x = 1;
	if (!args[1] || is_only_spaces(args[1]) == 1)
	{
		write(1, "\n", 1);
		return ;
	}
	if (check_parameter(args) == 0)
		flag = 1;
	if (flag == 0)
		x = 2;
	while (args[x])
	{
		write_args(x, 0, args);
		if (args[++x])
			write(1, " ", 1);
	}
	if (flag == 1)
		write(1, "\n", 1);
}
