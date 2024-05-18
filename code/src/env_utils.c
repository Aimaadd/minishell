/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeerber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 13:20:25 by mmeerber          #+#    #+#             */
/*   Updated: 2024/05/18 16:11:27 by mmeerber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

int		check_size(char *s1, char *s2)
{
	int x;
	int	y;

	x = 0;
	while (s1[x])
		x++;
	y = 0;
	while (s2[x])
		y++;
	if (x >= y)
		return (x);
	else
		return (y);
}

char	*ft_getenv(t_env *env, char *name_var)
{
	t_env	*temp;
	char	*value;
	int		check;

	temp = env;
	while (temp)
	{
		check_size
		check = ft_strncmp(temp->variable, name_var, ft_strlen(name_var));
		if (check == 0)
			return (temp->value);
		temp = temp->next;
	}
	return (NULL);
}
