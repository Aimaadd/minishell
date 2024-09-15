/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abentaye <abentaye@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 10:23:04 by gmallet           #+#    #+#             */
/*   Updated: 2024/09/15 14:28:43 by abentaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static uint32_t	atoi_buf(char *str, unsigned int old_status)
{
	uint32_t	res;

	if (old_status < 10)
	{
		*str = (old_status % 10) + '0';
		return (1);
	}
	res = atoi_buf(str, old_status / 10);
	str[res] = (old_status % 10) + '0';
	return (res + 1);
}

static uint32_t	cpy_old_status(char *str)
{
	if (g_ms.old_status < 0)
	{
		*(str++) = '-';
		return (atoi_buf(str, -(g_ms.old_status)) + 1);
	}
	return ((atoi_buf(str, g_ms.old_status)));
}

static int	cpy_env(char *env, char **word)
{
	if (env == NULL)
		return (1);
	while (*env)
		*((*word)++) = *(env++);
	return (OK);
}

int	expand(char **line, char **word)
{
	if (!(**line == '$'
			&& (ft_isenv(*((*line) + 1)) || ((*((*line) + 1) == '?')))))
		return (0);
	++(*line);
	if ((**line) == '?')
	{
		++(*line);
		(*word) += cpy_old_status(*word);
		return (1);
	}
	return (!(cpy_env(get_env_from_line(line), word)));
}
