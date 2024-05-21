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
	int		check;
	char	*home;

	home = ft_getenv(env, "HOME");
	if (!path)
	{
		if (chdir(home) == -1)
			perror("");
		update_value_env(home, "PWD", env);
		return ;
	}
	if (chdir(path) == -1)
		perror("");
	else
		update_value_env(getcwd(0, 0), "PWD", env);
	return ;
}
