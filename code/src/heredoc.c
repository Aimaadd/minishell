/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abentaye <abentaye@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 08:53:11 by abentaye          #+#    #+#             */
/*   Updated: 2024/08/12 14:45:09 by abentaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

// int	temp_file_create(void)
// {
// 	int	file;

// 	file = open("temp.txt", O_RDWR | O_CREAT, 0644);
// 	// printf("<%d>\n", file);
// 	if (file < 0)
// 	{
// 		perror("Error creating temporary file\n");
// 		exit (1);
// 	}
// 	// printf("%s\n", strerror(errno));
// 	return (file);
// }

char	*heredoc_loop(void)
{
	char	*heredoc;

	heredoc = readline("heredoc> ");
	if (!heredoc)
		exit(1);
	return (heredoc);
}

void	handle_heredoc(char *delim)
{
	char	*heredoc_line;
	char	*stock;

	stock = NULL;
	heredoc_line = NULL;
	while (1)
	{
		heredoc_line = heredoc_loop();
		if (stock)
		{
			if (!ft_strncmp(heredoc_line, delim, ft_strlen(delim)))
				break ;
			stock = ft_strjoin(stock, "\n");
		}
		stock = ft_strjoin(stock, heredoc_line);
	}
	printf("%s\n", stock);
}
