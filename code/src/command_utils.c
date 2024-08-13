/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abentaye <abentaye@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 15:38:15 by abentaye          #+#    #+#             */
/*   Updated: 2024/08/13 14:00:06 by abentaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

int	get_number_command(t_cmd *cmd)
{
	t_cmd	*tmp;
	int		number_of_command;

	number_of_command = 0;
	tmp = cmd;
	while (tmp)
	{
		tmp = tmp->next;
		number_of_command++;
	}
	return (number_of_command);
}
