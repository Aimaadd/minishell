/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abentaye <abentaye@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 13:46:57 by mmeerber          #+#    #+#             */
/*   Updated: 2024/06/11 11:04:37 by abentaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

t_env	*create_element(char *content)
{
	t_env	*new;
	char	**tab;
	char	*value;

	new = malloc(sizeof(t_env));
	if (!new)
		return (NULL);
	tab = ft_split(content, '=');
	if (!tab)
		return (NULL);
	if (getenv(tab[0]))
		value = getenv(tab[0]);
	else
		value = tab[1];
	new->variable = tab[0];
	new->value = value;
	new->next = NULL;
	return (new);
}

int		add_element(t_env **copy_env, char *content)
{
	t_env	*new;
	t_env	*last;

	new = create_element(content);
	if (!new)
		return (1);
	if (*copy_env == NULL)
	{
		*copy_env = new;
		return (0);
	}
	last = *copy_env;
	while (last->next)
		last = last->next;
	last->next = new;
	return (0);
}

t_env	*create_copy_env(char **env)
{
	int 			x;
	t_env	*copy_env;

	x = 0;
	copy_env = NULL;
	while (env[x])
	{
		add_element(&copy_env, env[x]);
		x++;
	}
	return (copy_env);
}
