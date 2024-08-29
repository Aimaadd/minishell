/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abentaye <abentaye@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 15:31:34 by abentaye          #+#    #+#             */
/*   Updated: 2024/08/29 22:27:27 by abentaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

void ft_exit_status(int status)
{
	gc_clean(&(g_ms->gc));
	gc_clean(&(g_ms->gcenv));
	exit(status);
}

void	ft_exit(void)
{
	return ft_exit_status(1);
}