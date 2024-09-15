/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_getenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abentaye <abentaye@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 16:35:30 by abentaye          #+#    #+#             */
/*   Updated: 2024/09/15 14:40:15 by abentaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char *get_equal(char *str)
{
	int i;

	i = 0;
	while (str[i] && str[i] != '=')
		i++;
	return (str + i + 1);
}

char	*ms_getenv(char *envname)
{
	size_t	en_len;
	size_t	i;

	en_len = ft_strlen(envname);
	if (en_len == 0)
		return (NULL);
	i = 0;
	while (g_ms.envs[i])
	{
		if (!ft_strncmp(envname, g_ms.envs[i], en_len))
			return (get_equal(g_ms.envs[i]));
		++i;
	}
	return (NULL);
}
