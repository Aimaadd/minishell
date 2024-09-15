/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   right_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abentaye <abentaye@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 18:17:29 by abentaye          #+#    #+#             */
/*   Updated: 2024/09/15 12:46:45 by abentaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*find_path(char **env)
{
	int	x;

	x = 0;
	while (env[x])
	{
		if (ft_strncmp(env[x], "PATH", 4) == 0)
			break ;
		x++;
	}
	return (&env[x][5]);
}

void	free_split(char **tab)
{
	int	i;

	i = -1;
	while (tab[++i])
		free(tab[i]);
	free(tab);
}

char	*right_path(char *cmd, char **env)
{
	char	**tab_path;
	char	*path;
	char	*newenv;
	int		x;

	newenv = find_path(env);
	tab_path = ft_split_path(newenv, ':');
	x = -1;
	while (tab_path[++x])
	{
		path = ft_strjoin(tab_path[x], cmd);
		if (access(path, X_OK) == 0)
		{
			free_split(tab_path);
			return (path);
		}
		free(path);
	}
	free_split(tab_path);
	return (NULL);
}
