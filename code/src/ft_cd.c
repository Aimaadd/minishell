/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeerber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 14:29:50 by mmeerber          #+#    #+#             */
/*   Updated: 2024/05/18 15:13:00 by mmeerber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

void	ft_cd(char *path, t_env *env)
{
	int		check;
	char	*home;

	home = ft_getenv(env, "HOME");
	printf("result = %s\n", home);
	if (!path)
	{
		if (chdir(home) == -1)
			perror("");
		return ;
	}
	if (chdir(path) == -1)
		perror("");
}
