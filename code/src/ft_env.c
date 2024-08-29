/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abentaye <abentaye@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 15:31:42 by abentaye          #+#    #+#             */
/*   Updated: 2024/08/29 21:50:11 by abentaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

void	ft_env(t_env *env)
{
	t_env	*env_tmp;

	env_tmp = env;
	while (env_tmp)
	{
		if (env_tmp->value[0])
			printf("%s=%s\n", env_tmp->variable, env_tmp->value);
		env_tmp = env_tmp->next;
	}
}
