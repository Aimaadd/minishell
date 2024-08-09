/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abentaye <abentaye@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 08:53:11 by abentaye          #+#    #+#             */
/*   Updated: 2024/08/09 21:35:44 by abentaye         ###   ########.fr       */
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

// int	display_heredoc(void)
// {
// 	char	*buf;
// 	int bytes_read;
// 	int fd;
// 	char *str;

// 	fd = open("temp.txt", O_RDONLY);

// 	bytes_read = 1;
// 	buf = malloc(sizeof(char) * 256 + 1);
// 	while (bytes_read)
// 	{
// 		bytes_read = read(fd, buf, 256);
// 		buf[bytes_read] = '\0';
// 		str = ft_strjoin(str, buf);
// 	}
// 	close (fd);
// 	return (0);
// }

void	handle_heredoc(char *delim)
{
	char	*heredoc_line;
	char 	*stock;

	stock = NULL;
	heredoc_line = NULL;
	while (1)
	{
		heredoc_line = heredoc_loop();
		if (stock)
		{
			if (!ft_strncmp(heredoc_line, delim, ft_strlen(delim)))
				break;
			stock = ft_strjoin(stock, "\n");
		}
		stock = ft_strjoin(stock, heredoc_line);
	}
	printf("%s\n", stock);
}

// int	main(int argc, char **argv)
// {
// 	if (argc < 2)
// 	{
// 		fprintf(stderr, "Usage: %s <delimiter>\n", argv[0]);
// 		return 1;
// 	}
// 	handle_heredoc(argv[1]);
// 	return 0;
// }
