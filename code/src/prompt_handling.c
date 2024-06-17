/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt_handling.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abentaye <abentaye@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 12:54:11 by abentaye          #+#    #+#             */
/*   Updated: 2024/06/14 16:43:33 by abentaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

char *prompt_handler(void)
{
    char *line;
    
    line = readline("minishell$ ");
    if (line && line[0] == '\0')
        write(1, "bomboclaat\n", 11);

    return (line);
}
