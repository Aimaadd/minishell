/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abentaye <abentaye@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 15:57:55 by abentaye          #+#    #+#             */
/*   Updated: 2024/09/15 12:46:33 by abentaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_swp(char **x, char **y)
{
	char	*z;

	z = *x;
	*x = *y;
	*y = z;
}

void	print_list(char *argv, char **env)
{
	int	i;
	int	j;

	if (!argv)
	{
		i = 0;
		while (env[i])
		{
			j = i + 1;
			while (env[j])
			{
				if (ft_strncmp(env[i], env[j], 1) > 0)
					ft_swp(&env[i], &env[j]);
				j++;
			}
			i++;
		}
		i = 0;
		while (env[i])
			printf("%s\n", env[i++]);
	}
}

int	get_size(char **env)
{
	int	i;

	i = 0;
	while (env[i])
		i++;
	return (i);
}

char	*gc_strdup(char *str)
{
	size_t	i;
	char	*ret;

	if (str == NULL)
		return (NULL);
	i = 0;
	ret = gc_malloc(&(g_ms.gcenv), (ft_strlen(str) + 1));
	if (ret == NULL)
		return (NULL);
	while (str[i])
	{
		ret[i] = str[i];
		++i;
	}
	ret[i] = '\0';
	return (ret);
}
