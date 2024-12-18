/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abentaye <abentaye@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 16:45:22 by abentaye          #+#    #+#             */
/*   Updated: 2024/09/15 15:48:05 by abentaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_isspace(char c)
{
	return ((c == ' ') || ((c > 8) && (c < 14)));
}

int	ft_isoperator(char c)
{
	return ((c == '<') || (c == '>') || (c == '|'));
}

int	ft_isquote(char c)
{
	return ((c == '\'') || (c == '\"'));
}

int	ft_isenv(char c)
{
	return (ft_isalpha(c) || ft_isdigit(c) || (c == '_'));
}
