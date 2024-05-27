/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abentaye <abentaye@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 18:23:00 by abentaye          #+#    #+#             */
/*   Updated: 2024/05/27 12:17:51 by abentaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

void	init_input(t_input *entry)
{
	entry = malloc(sizeof(t_input));
	if (!entry)
		return ;
	entry->index = 0;
	entry->list = NULL;
}
