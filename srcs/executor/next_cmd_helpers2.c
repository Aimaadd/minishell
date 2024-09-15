/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   next_cmd_helpers2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abentaye <abentaye@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 17:06:48 by abentaye          #+#    #+#             */
/*   Updated: 2024/09/15 17:10:42 by abentaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	handle_setup_error(int er, t_cmd *cmd, int *pfd, t_token *tkn, int dh)
{
	if (er == INT_ERROR)
		return ;
	close_pipes_and_print_error(cmd, pfd);
	call_exec_next_cmd(tkn, dh);
}
