/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abentaye <abentaye@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 15:40:08 by abentaye          #+#    #+#             */
/*   Updated: 2024/06/06 10:32:20 by abentaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

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

char **split_pipe_redir(char *line)
{
	char **result;
	char *start;
	char *end;

	if (!line)
		return (printf("fail\n"), NULL);
	result = (char**)ft_calloc(4, sizeof(char*));
	start = line;
	end = ft_strpbrk(line, "|><$");
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

static char    *ft_strchr_multi(const char *s, const char *delim)
{
    while (*s)
    {
        if (ft_strchr(delim, *s))
            return ((char *)s);
        s++;
    }
    return (NULL);
}

static int	ft_count_elem(char const *s, char *delim)
{
    int	count;
    int	i;

    i = 0;
    count = 0;
    while (s[i])
    {
        if (ft_strchr(delim, s[i]))
            count++;
        else if (i == 0 || ft_strchr(delim, s[i - 1]))
            count++;
        i++;
    }
    return (count);
}

static void	fill_tab(char **tab, char const *s, char *delim, int *i)
{
    char	*temp;
    int		j;

    j = 0;
    while (s[*i])
    {
        while (ft_strchr(delim, s[*i]) && s[*i])
        {
            char *delim_str = ft_substr(s, *i, 1);
            tab[j++] = delim_str;
            (*i)++;
        }
        if (s[*i])
        {
            temp = ft_strchr_multi(&s[*i], delim);
            if (temp)
                tab[j] = ft_substr(s, *i, temp - &s[*i]);
            else
                tab[j] = ft_substr(s, *i, ft_strlen(&s[*i]));
            while (s[*i] && !ft_strchr(delim, s[*i]))
                (*i)++;
            j++;
        }
    }
    tab[j] = NULL;
}

char	**ft_strsplit(char const *s, char *delim)
{
    char	**tab;
    int		i;

    if (!s || !(tab = malloc(sizeof(char *) * (ft_count_elem(s, delim) + 1))))
        return (NULL);
    i = 0;
    fill_tab(tab, s, delim, &i);
    return (tab);
}