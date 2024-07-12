/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt_handling.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abentaye <abentaye@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 12:54:11 by abentaye          #+#    #+#             */
/*   Updated: 2024/07/12 17:33:06 by abentaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

char	*prompt_handler(void)
{
	char	*line;

	line = readline("minishell$ ");
	add_history(line);
	if (line == NULL)
		exit(1);
	return (line);
}
