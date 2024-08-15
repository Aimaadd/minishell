/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abentaye <abentaye@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 15:40:08 by abentaye          #+#    #+#             */
/*   Updated: 2024/08/15 02:17:38 by abentaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

//This function will see if there is a pipe or redirection in the input
int	pipe_or_redirection(char *line)
{
	int	i;

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

char	**split_pipe_redir(char *line)
{
	char	**result;
	char	*start;
	char	*end;

	result = (char **)ft_calloc(4, sizeof(char *));
	start = line;
	end = ft_strpbrk(line, "|><");
	if (!result || !end)
	{
		if (result)
			free(result);
		return (NULL);
	}
	result[0] = ft_substr(start, 0, end - start);
	result[1] = ft_substr(end, 0, 1);
	result[2] = ft_strdup(end + 1);
	result[3] = NULL;
	return (result);
}

//This function will return the string between two quotes
char	*between_quotes(char *line)
{
	int		i;
	int		j;
	char	*str;

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

char	*to_expand(t_list *input)
{
	char	*temp;
	int		i;
	int		j;
	
	temp = malloc(sizeof (char *));
	if (!temp)
		return (NULL);
	j = 0;
	i = 1;
	while (input->content[i])
	{
		temp[j] = input->content[i];
		j++;
		i++;
	}
	temp[j] = '\0';
	if (getenv(temp))
		return (input->content = getenv(temp));
	else
		write(1, "\n", 1);
	free(temp);
	return (input->content = "\n");
}

int	is_parameter(const char *str)
{
	int	i;

	if (str[0] == '-' && str[1])
	{
		i = 1;
		while (str[i])
		{
			if (str[i] == ' ')
				return (1);
			i++;
		}
		return (0);
	}
	return (1);
}
