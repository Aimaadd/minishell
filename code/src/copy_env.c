/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abentaye <abentaye@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 13:46:57 by mmeerber          #+#    #+#             */
/*   Updated: 2024/09/07 19:22:03 by abentaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

void	create_element_with_content(char **tab, char *value, t_env *new)
{
	if (getenv(tab[0]))
		value = getenv(tab[0]);
	else
		if (tab[1])
			value = tab[1];
	new->variable = tab[0];
	new->value = value;
	new->next = NULL;
}

t_env	*create_element(char *content)
{
	t_env	*new;
	char	**tab;
	char	*value;

	value = NULL;
	new = malloc(sizeof(t_env));
	if (!new)
		return (NULL);
	tab = ft_split(content, '=');
	if (!tab)
		return (NULL);
	if (tab[1])
		create_element_with_content(tab, value, new);
	else
	{
		new->variable = tab[0];
		new->value = "";
		new->next = NULL;
	}
	return (new);
}

int	add_element(t_env **copy_env, char *content)
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

int	env_empty(t_env **copy_env)
{
	char	*pwd;

	pwd = ft_strjoin("PWD=", getcwd(0, 0));
	if (!pwd)
		return (1);
	if (add_element(copy_env, "SHLVL=1") == 1)
		return (1);
	if (add_element(copy_env, "_=/usr/bin/env") == 1)
		return (1);
	if (add_element(copy_env, "OLDPWD") == 1)
		return (1);
	if (add_element(copy_env, pwd) == 1)
		return (1);
	return (0);
}

void	free_env_list(t_env *env)
{
	t_env	*temp;

	while (env)
	{
		temp = env;
		env = env->next;
		if (temp->variable)
			free(temp->variable);
		if (temp->value)
			free(temp->value);
		free(temp);
	}
}
