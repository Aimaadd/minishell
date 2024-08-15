/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solo_execute.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abentaye <abentaye@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 21:18:48 by abentaye          #+#    #+#             */
/*   Updated: 2024/08/15 23:03:17 by abentaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

int list_size(t_list *list)
{
    int count = 0;
    while (list)
    {
        count++;
        list = list->next;
    }
    return count;
}

char **fill_array_from_list(t_list *list)
{
    int size = list_size(list);
    char **array = malloc((size + 1) * sizeof(char *));
    if (!array)
        return NULL;

    int i = 0;
    while (list)
    {
        array[i] = strdup(list->content);
        if (!array[i])
        {
            while (i > 0)
                free(array[--i]);
            free(array);
            return NULL;
        }
        i++;
        list = list->next;
    }
    array[i] = NULL;
    return array;
}
