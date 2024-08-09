/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abentaye <abentaye@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 08:53:11 by abentaye          #+#    #+#             */
/*   Updated: 2024/08/09 19:36:47 by abentaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

int	temp_file_create(void)
{
	int	file;

	file = open("temp.txt", O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (file < 0)
	{
		perror("Error creating temporary file\n");
		exit (1);
	}
	return (file);
}

char	*heredoc_loop(void)
{
	char	*heredoc;

	heredoc = readline("heredoc> ");
	if (!heredoc)
		exit (1);
	if (heredoc == NULL)
		exit(1);
	return (heredoc);
}

int	display_heredoc(int temp_file)
{
	char	buffer[256];
	int	bytes_read;
	
	bytes_read = 0;
	while ((bytes_read = read(temp_file, buffer, sizeof(buffer) + 1)) > 0)
	{
		buffer[bytes_read + 1] = '\0';
		printf("%s", buffer);
	}
	close (temp_file);
	return (0);
}

void	handle_heredoc(char *delim)
{
	int		temp_file;
	char	*heredoc_line;

	temp_file = temp_file_create();
	while (1)
	{
		heredoc_line = heredoc_loop();
		if (ft_strncmp(heredoc_line, delim, ft_strlen(heredoc_line)) == 0)
			break ;
		write(temp_file, heredoc_line, ft_strlen(heredoc_line));
		write(temp_file, "\n", 1);
		free(heredoc_line);
	}
	if(display_heredoc(temp_file) != 0)
	{
		close(temp_file);
		exit (1);
	}
	if (unlink("temp.txt") == -1)
		perror("Error deleting temporary file\n");
}

int	main(int argc, char **argv)
{
	if (argc < 2)
	{
		fprintf(stderr, "Usage: %s <delimiter>\n", argv[0]);
		return 1;
	}
	handle_heredoc(argv[1]);
	return 0;
}
