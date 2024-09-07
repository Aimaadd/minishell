/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abentaye <abentaye@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 15:29:33 by abentaye          #+#    #+#             */
/*   Updated: 2024/09/07 19:15:17 by abentaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

int	count_env_vars(t_env *env_copy)
{
	int		count;
	t_env	*tmp_env;

	count = 0;
	tmp_env = env_copy;
	while (tmp_env)
	{
		count++;
		tmp_env = tmp_env->next;
	}
	return (count);
}

char	*create_env_string(t_env *env)
{
	char	*env_string;
	int		len;

	len = strlen(env->variable) + strlen(env->value) + 2;
	env_string = malloc(sizeof(char) * len);
	if (!env_string)
		return (NULL);
	sprintf(env_string, "%s=%s", env->variable, env->value);
	return (env_string);
}

int	add_envp(t_cmd *command, t_env *env_copy)
{
	int		i;
	int		env_count;
	t_env	*tmp_env;

	env_count = count_env_vars(env_copy);
	command->envp = malloc(sizeof(char *) * (env_count + 1));
	if (!command->envp)
		return (1);
	i = 0;
	tmp_env = env_copy;
	while (tmp_env)
	{
		command->envp[i] = create_env_string(tmp_env);
		if (!command->envp[i])
			return (1);
		i++;
		tmp_env = tmp_env->next;
	}
	command->envp[i] = NULL;
	return (0);
}
