/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeerber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 13:46:57 by mmeerber          #+#    #+#             */
/*   Updated: 2024/05/16 18:14:19 by mmeerber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

t_env	*create_element(char *content)
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

int		add_element(t_env *copy_env, char *content)
{
	t_env	*new;
	t_env	*last;

	new = create_element(content);
	if (!new)
		return (1);
	if (copy_env == NULL)
		copy_env = new;
	while (copy_env->next != NULL)
		last = last->next;
	last->next = new;
}

void	create_copy_env(char **env)
{
	int x;
	t_env	*copy_env;

	x = 0;
	copy_env = NULL;
	while (env[x])
	{
		copy_env = create_element(env[x]);
		//printf("%s = %s\n", copy_env->variable, copy_env->value);
		x++;
	}
}
