/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeerber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 14:29:50 by mmeerber          #+#    #+#             */
/*   Updated: 2024/05/20 18:47:32 by mmeerber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

void	ft_cd(char *path, t_env *env)
{
	char	*home;
	char	*old_pwd;
	char	*pwd;

	home = ft_getenv(env, "HOME");
	old_pwd = ft_getenv(env, "OLDPWD");
	pwd = ft_getenv(env, "PWD");
	if (!path)
	{
		if (chdir(home) == -1)
			perror("");
		update_value_env(home, "PWD", env);
		update_value_env(pwd, "OLDPWD", env);
		return ;
	}
	if (ft_strncmp(path, "-", ft_strlen(path) == 0)
	{
		if (chdir(old_pwd) == -1)
			perror("");
		update_value_env(getcwd(0, 0), "PWD", env);
		update_value_env(pwd, "OLDPWD", env);
		return ;
	}
	else
		perror("");
	if (chdir(path) == -1)
		perror("");
	else
	{
		update_value_env(getcwd(0, 0), "PWD", env);
		update_value_env(pwd, "OLDPWD", env);
	}
	return ;
}
