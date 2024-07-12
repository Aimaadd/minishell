/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abentaye <abentaye@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 15:40:08 by abentaye          #+#    #+#             */
/*   Updated: 2024/07/12 14:03:01 by abentaye         ###   ########.fr       */
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

//This function will split whats before and after the pipe or redirection into
// three strings and return the one in the middle
// static void copy_chars(char *str, char *line, int *i, int *j)
// {
//     while (line[*i] != '|' && line[*i] != '>' && line[*i] != '<' && line[*i])
//     {
//         str[*j] = line[*i];
//         (*i)++;
//         (*j)++;
//     }
// }

char **split_pipe_redir(char *line)
{
    char **result = (char**)ft_calloc(4, sizeof(char*));
    char *start = line;
    char *end = ft_strpbrk(line, "|><");

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

char *to_expand(t_list *input)
{
    char *str;
    int i;
    int j;

    i = 0;
    j = 0;
    str = malloc(sizeof(char) * (ft_strlen(input->content) + 1));
    if (!str)
        return (NULL);
    while (input->content[i])
    {
        if (input->content[i] == '$')
        {
            i++;
            while (input->content[i] && input->content[i] != ' ')
            {
                str[j] = input->content[i];
                i++;
                j++;
            }
        }
        else
        {
            str[j] = input->content[i];
            i++;
            j++;
        }
    }
    str[j] = '\0';
    return str;
}