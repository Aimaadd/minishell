/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abentaye <abentaye@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 14:29:50 by mmeerber          #+#    #+#             */
/*   Updated: 2024/08/10 15:50:02 by mmeerber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

char	*if_tield_in_path(char *path, char *home)
{
	char	*new_path;
	char	**tab;
	int		x;

	x = 0;
	if (!path)
		return (NULL);
	while (path[x])
	{
		if (path[x] == '~')
		{
			tab = ft_split(path, '~');
			new_path = ft_strjoin(home, tab[0]);
		}
		x++;
	}
	free(path);
	return (new_path);
}

void	to_home(char *path, char *home, char *pwd, t_env *env)
{
	path = if_tield_in_path(path, home);
	if (chdir(home) == -1)
		perror("");
	update_value_env(home, "PWD", env);
	update_value_env(pwd, "OLDPWD", env);
}

void	ft_cd(char *path, t_env *env)
{
	char	*home;
	char	*old_pwd;
	char	*pwd;

	home = ft_getenv(env, "HOME");
	old_pwd = ft_getenv(env, "OLDPWD");
	pwd = ft_getenv(env, "PWD");
	if (!path || *path == '~')
		to_home(path, home, pwd, env);
	else if (ft_strncmp(path, "-", ft_strlen(path)) == 0)
	{
		if (chdir(old_pwd) == -1)
			perror("");
		update_value_env(getcwd(0, 0), "PWD", env);
		update_value_env(pwd, "OLDPWD", env);
	}
	else if (chdir(path) == -1)
		perror("");
	else
	{
		update_value_env(getcwd(0, 0), "PWD", env);
		update_value_env(pwd, "OLDPWD", env);
	}
}
