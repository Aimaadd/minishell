/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abentaye <abentaye@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 13:20:25 by mmeerber          #+#    #+#             */
/*   Updated: 2024/06/12 11:02:55 by abentaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

void	print_env(t_env *env)
{
	t_env *tmp;

	tmp = env;
	while (tmp)
	{
		printf("%s\n", tmp->variable);
		tmp = tmp->next;
	}
	return ;
}

int		check_size(char *s1, char *s2)
{
	int x;
	int	y;

	x = 0;
	while (s1[x])
		x++;
	y = 0;
	while (s2[y])
		y++;
	if (x >= y)
		return (x);
	else
		return (y);
}

char	*ft_getenv(t_env *env, char *name_var)
{
	t_env	*temp;
	// char	*value;
	int		check;
	int		len;

	temp = env;
	while (temp)
	{
		len = check_size(temp->variable, name_var);
		check = ft_strncmp(temp->variable, name_var, len);
		if (check == 0)
			return (temp->value);
		temp = temp->next;
	}
	return (NULL);
}

void	update_value_env(char *value, char *variable, t_env *env)
{
	int len;
	int	x;
	t_env	*tmp;

	tmp = env;
	while (tmp)
	{
		len = check_size(tmp->variable, variable);
		x = ft_strncmp(tmp->variable, variable, len);
		if (x == 0)
			break;
		tmp = tmp->next;	
	}
	tmp->value = value;
	return ;
}

// char **conv_tab_env(t_env *env_copy)
// {
// 	char **tab_env;
// 	t_env	*tmp;
// 	int	x;

// 	x = 0;
// 	tmp = env_copy;
// 	while (tmp)
// 	{
// 		x++;
// 		tmp = tmp->next;
// 	}
// 	tab_env = malloc(sizeof(char *) * (x + 1));
// 	tmp = env_copy;
// 	x = 0;
// 	while (tmp)
// 	{
// 		tab_env[x] = ft_strjoin(tmp->variable, tmp->value);
// 		x++;
// 		tmp = tmp->next;
// 	}
// 	return (tab_env);
// }

static void	free_tab(char **tab)
{
    int	i;

    i = 0;
    while (tab[i])
    {
        free(tab[i]);
        i++;
    }
    free(tab);
}

char	**conv_tab_env(t_env *env_copy)
{
    char	**tab_env;
    t_env	*tmp;
    int		x;

    x = 0;
    tmp = env_copy;
    while (tmp)
    {
        x++;
        tmp = tmp->next;
    }
    if (!(tab_env = malloc(sizeof(char *) * (x + 1))))
        return (NULL);
    x = 0;
    tmp = env_copy;
    while (tmp)
    {
        tab_env[x] = ft_strjoin(ft_strjoin(tmp->variable, "="), tmp->value);
        if (!tab_env[x])
            return (free_tab(tab_env), NULL);
        x++;
        tmp = tmp->next;
    }
    tab_env[x] = NULL;
    return (tab_env);
}