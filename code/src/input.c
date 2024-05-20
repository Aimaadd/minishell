/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abentaye <abentaye@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 20:13:35 by abentaye          #+#    #+#             */
/*   Updated: 2024/05/20 20:20:23 by abentaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

void print_list(t_list *list)
{
    while (list)
    {
        if (list->content)
            printf("%s\n", list->content);
        list = list->next;
    }
}

// this function creates a new node to my list
void    *new_node(t_list **list, char *content)
{
    t_list  *new;
    t_list  *tmp;

    new = malloc(sizeof(t_list));
    if (!new)
        return (NULL);
    new->content = content;
    new->next = NULL;
    if (*list == NULL)
    {
        *list = new;
        return (new);
    }
    tmp = *list;
    while (tmp->next != NULL)
        tmp = tmp->next;
    tmp->next = new;
    return (new);
}


//this function will turn a str into a list
t_list *input_to_list(char *input, t_input *entry)
{
    char **splinput;
    int i;

    splinput = ft_split(input, ' ');
    i = 0;
    while (splinput[i])
    {
        new_node(&entry->list, splinput[i]);
        i++;
    }
    return (entry->list);
}
// malloc la struct puis init la struct 
// int main(int argc, char **argv)
// {
//     t_input *input;
//     int i;

//     input = malloc(sizeof(t_input));
//     if (!input)
//         return (1);
//     input->list = NULL;
//     input->index = 0;
//     i = 1;
//     while (argv[i])
//     {
//         input->list = input_to_list(argv[i], input);
//         i++;
//     }
//     print_list(input->list);
//     return 0;
// }
