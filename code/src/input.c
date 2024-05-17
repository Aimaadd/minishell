/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abentaye <abentaye@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 20:13:35 by abentaye          #+#    #+#             */
/*   Updated: 2024/05/17 19:07:06 by abentaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

// this function creates a new node to my list
t_list  *new_node(t_list **list, char *content)
{
    t_list *new;

    new = (t_list *)malloc(sizeof(t_list));
    if (!new)
        return (NULL);
    new->content = content;
    new->next = *list;
    return (new);
}

//this function will turn a str into a list
t_input *input_to_list(char *input, t_input *entry)
{
    char **splinput;
    int i;

    i = 0;
    splinput = ft_split(input, ' ');
    while (splinput[i] != NULL)
    {
        entry->list = new_node(&entry->list, splinput[i]);
        printf("%s\n", entry->list->content);
        printf("%s\n", )
        i++;
    }
    return (entry);
}

int main(int argc, char **argv)
{
    t_input *input;
    int i;

    input = malloc(sizeof(t_input));
    if (!input)
        return (1);
    input->list = NULL;
    
    i = 1;
    while (argv[i])
    {
        input = input_to_list(argv[i], input);
        i++;
    }
    return 0;
}
