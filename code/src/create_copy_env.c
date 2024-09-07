/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_copy_env.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abentaye <abentaye@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 19:20:52 by abentaye          #+#    #+#             */
/*   Updated: 2024/09/07 19:22:17 by abentaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

char	*get_pwd(void)
{
	char	*buffer;

	buffer = malloc(PATH_MAX);
	if (!buffer)
		return (NULL);
	if (!getcwd(buffer, PATH_MAX))
	{
		free(buffer);
		return (NULL);
	}
	return (buffer);
}

int	add_initial_elements(t_env **copy_env)
{
	if (add_element(copy_env, "_=/usr/bin/env") == 1
		|| add_element(copy_env, "OLDPWD") == 1
		|| add_element(copy_env, get_pwd()) == 1)
	{
		free_env_list(*copy_env);
		return (1);
	}
	return (0);
}

int	copy_env_elements(t_env **copy_env, char **env)
{
	int	x;

	x = 0;
	while (env[x])
	{
		if (add_element(copy_env, env[x]) == 1)
		{
			free_env_list(*copy_env);
			return (1);
		}
		x++;
	}
	return (0);
}

t_env	*create_copy_env(char **env)
{
	t_env	*copy_env;

	copy_env = NULL;
	if (!env || !*env)
	{
		if (env_empty(&copy_env) == 1)
			return (NULL);
		return (copy_env);
	}
	if (copy_env_elements(&copy_env, env) == 1)
		return (NULL);
	if (add_initial_elements(&copy_env) == 1)
		return (NULL);
	return (copy_env);
}
