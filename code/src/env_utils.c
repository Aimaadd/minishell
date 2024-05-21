/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeerber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 13:20:25 by mmeerber          #+#    #+#             */
/*   Updated: 2024/05/20 19:12:28 by mmeerber         ###   ########.fr       */
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
	while (s2[y])
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
	int		len;

	temp = env;
	while (temp)
	{
		len = check_size(temp->variable, name_var);
		check = ft_strncmp(temp->variable, name_var, len);
		if (check == 0)
			return (temp->value);
		temp = temp->next;
	}
	return (NULL);
}

void	update_value_env(char *value, char *variable, t_env *env)
{
	int len;
	int	x;

	t_env	*tmp;
	while (tmp)
	{
		len = check_size(tmp->variable, variable);
		printf("value : %s, variable %s\n", value, variable);
		x = ft_strncmp(tmp->variable, variable, len);
		if (x == 0)
			break;
		tmp = tmp->next;	
	}
	tmp->value = value;
	return ;
}
