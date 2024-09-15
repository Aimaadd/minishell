/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_getenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abentaye <abentaye@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 16:35:30 by abentaye          #+#    #+#             */
/*   Updated: 2024/09/15 12:46:53 by abentaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

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
		if (!ft_strncmp(envname, g_ms.envs[i], en_len - 1))
			return (g_ms.envs[i] + en_len + 1);
		++i;
	}
	return (NULL);
}
