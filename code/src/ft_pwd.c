/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abentaye <abentaye@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 18:00:56 by abentaye          #+#    #+#             */
/*   Updated: 2024/07/14 18:00:57 by abentaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

void	ft_pwd(void)
{
	char	*path;

	path = getcwd(0, 0);
	if (!path)
		perror("");
	else
		printf("%s\n", path);
	return ;
}
