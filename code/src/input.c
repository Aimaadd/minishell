/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abentaye <abentaye@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 20:13:35 by abentaye          #+#    #+#             */
/*   Updated: 2024/06/06 09:42:23 by abentaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

// this function creates a new node to my list
void	*new_node(t_list **list, char *content)
{
	t_list	*new;
	t_list	*tmp;

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

// this function will turn a str into a list
// t_list	*input_to_list(t_input *entry)
// {
// 	char	**splinput;
// 	int		i;
	
// 	// PARSE THE INPUT AND ADD IT TO THE LIST
// 	splinput = ft_split(entry->line, ' ');
// 	i = 0;
// 	while (splinput[i])
// 	{
// 		ft_lstadd_back(&entry->list, ft_lstnew(splinput[i]));
// 		i++;
// 	}
// 	free(splinput);
// 	return (entry->list);
// }

t_list	*input_to_list(t_input *entry)
{
    char	**splinput;
    char	**splpipe;
    int		i;
    int		j;

    // PARSE THE INPUT AND ADD IT TO THE LIST
	splpipe = malloc(sizeof(char*) * 4);
    splinput = ft_split(entry->line, ' ');
    i = 0;
    while (splinput[i])
    {
        splpipe = ft_strsplit(splinput[i], "|><");
        j = 0;
        while (splpipe[j])
        {
            ft_lstadd_back(&entry->list, ft_lstnew(splpipe[j]));
            j++;
        }
        free(splpipe);
        free(splinput[i]);
        i++;
    }
    free(splinput);
    return (entry->list);
}
