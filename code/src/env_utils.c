/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abentaye <abentaye@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 13:20:25 by mmeerber          #+#    #+#             */
/*   Updated: 2024/08/14 18:36:56 by abentaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

int	check_size(char *s1, char *s2)
{
	int	x;
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
	int		check;

	temp = env;
	while (temp)
	{
		check = ft_strncmp(temp->variable, name_var, ft_strlen(temp->variable));
		if (check == 0)
			return (temp->value);
		temp = temp->next;
	}
	return (NULL);
}

void	update_value_env(char *value, char *variable, t_env *env)
{
	int		len;
	int		x;
	t_env	*tmp;

	tmp = env;
	while (tmp)
	{
		len = check_size(tmp->variable, variable);
		x = ft_strncmp(tmp->variable, variable, len);
		if (x == 0)
			break ;
		tmp = tmp->next;
	}
	tmp->value = value;
	// printlist(tmp);
	return ;
}

void	free_tab(char **tab)
{
	int	i;

	i = -1;
	while (tab[++i])
		free(tab[i]);
	free(tab);
}

char	**conv_tab_env(t_env *env_copy)
{
	char	**tab_env;
	t_env	*tmp;
	int		x;

	x = 0;
	tmp = env_copy;
	while (tmp)
	{
		x++;
		tmp = tmp->next;
	}
	tab_env = malloc(sizeof(char *) * (x + 1));
	if (!tab_env)
		return (NULL);
	x = 0;
	tmp = env_copy;
	while (tmp)
	{
		tab_env[x] = ft_strjoinfree(ft_strjoin(tmp->variable, "="), tmp->value);
		if (!tab_env[x])
			return (free_tab(tab_env), NULL);
		x++;
		tmp = tmp->next;
	}
	return (tab_env[x] = NULL, tab_env);
}
