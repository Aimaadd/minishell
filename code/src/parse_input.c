/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abentaye <abentaye@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 15:40:08 by abentaye          #+#    #+#             */
/*   Updated: 2024/06/01 21:06:09 by abentaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

//from a char *line and i have to return a char **splinput in order to splinput.

// char    **parse_input(char *line)
// {
// 	char **str;
	
// 	str = between_quotes(line);
// 	return ()
// }

//This function will see if there is a pipe or redirection in the input
int	pipe_or_redirection(char *line)
{
	int i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '|')
			return (PIPE);
		if (line[i] == '>' || line[i] == '<')
			return (REDIRECTION);
		i++;
	}
	return (0);
}

//This function will split whats before and after the pipe or redirection into
// three strings and return the one in the middle
static void copy_chars(char *str, char *line, int *i, int *j)
{
	while (line[*i] != '|' && line[*i] != '>' && line[*i] != '<' && line[*i])
	{
		str[*j] = line[*i];
		(*i)++;
		(*j)++;
	}
}

char **split_pipe_redir(char *line)
{
	char **result;
	char *start;
	char *end;

	if (!line)
		return (printf("fail\n"), NULL);
	result = (char**)ft_calloc(4, sizeof(char*));
	start = line;
	end = ft_strpbrk(line, "|><");
	if (!result || !end)
	{
		if (result)
			free(result);
		return NULL;
	}

	result[0] = ft_substr(start, 0, end - start);
	result[1] = ft_substr(end, 0, 1);
	result[2] = ft_strdup(end + 1);
	result[3] = NULL;

	return (result);
}

//This function will return the string between two quotes
char *between_quotes(char *line)
{
	int i;
	int j;
	char *str;

	i = 0;
	j = 0;
	str = malloc(sizeof(char) * ft_strlen(line));
	if (!str)
		return (NULL);
	while (line[i])
	{
		if (line[i] == '\"')
		{
			i++;
			while (line[i] != '\"')
			{
				str[j] = line[i];
				i++;
				j++;
			}
		}
		i++;
	}
	str[j] = '\0';
	return (str);
}

// int main (int argc, char **argv)
// {
//     char *test;

//     test = "test\"un truc bizarre";
//     between_quotes(argv[1]);
//     // print the split string
//     printf("%s\n", split_pipe_redir(argv[1]));
//     printf("%s\n", argv[1]);
// }

int main (int argc, char **argv)
{
	char **split_result;
	int i;

	i = 0;
	split_result = split_pipe_redir(argv[1]);

	if (split_result)
	{
		while (split_result[i])
		{
			ft_putstr_fd(split_result[i], 1);
			ft_putchar_fd('\n', 1);
			free(split_result[i]);
			i++;
		}
		free(split_result);
	}

	return 0;
}