/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abentaye <abentaye@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 10:53:01 by abentaye          #+#    #+#             */
/*   Updated: 2024/09/15 12:46:23 by abentaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	pwd_builtin(int argc, char **argv)
{
	char	*buf;

	(void)argv;
	if (argc == 2)
	{
		print_error("pwd", "too many arguments", NULL);
		return (1);
	}
	else
	{
		buf = gc_malloc(&(g_ms.gcan), sizeof(char) * 4096);
		if (buf == NULL)
			return (1);
		getcwd(buf, 4096);
		printf("%s\n", buf);
		gc_free(&(g_ms.gcan), (void **)&buf);
	}
	return (0);
}
