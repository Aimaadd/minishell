/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeerber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 13:46:57 by mmeerber          #+#    #+#             */
/*   Updated: 2024/05/16 17:06:14 by mmeerber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

t_env	*new_element(char *content)
{
	t_env	*new;
	char	**tab;

	new = malloc(sizeof(t_env));
	if (!new)
		return (NULL);
	tab = ft_split(content, '=');
	if (!tab)
		return (NULL);
	new->variable = tab[0];
	new->value = tab[1];
	new->next = NULL;
	return (new);
}

void	add_element(t_env *env, char *content)
{

}

void	create_copy_env(char **env)
{
	int x;
	t_env	*copy_env;

	x = 0;
	while (env[x])
	{
		copy_env = new_element(env[x]);
		//printf("%s = %s\n", copy_env->variable, copy_env->value);
		x++;
	}
}
