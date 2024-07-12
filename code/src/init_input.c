/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abentaye <abentaye@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 18:23:00 by abentaye          #+#    #+#             */
/*   Updated: 2024/07/12 19:29:08 by abentaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

void	init_input(t_input *entry)
{
	entry = (t_input *) malloc(sizeof(t_input));
	if (!entry)
		return ;
	entry->line = NULL;
	entry->index = 0;
	entry->list = NULL;
}

t_list	*ft_lstnew(char *content)
{
	t_list	*new;

	new = (t_list *) malloc(sizeof(*new));
	if (!new)
		return (NULL);
	new->content = content;
	new->type = 0;
	new->next = NULL;
	return (new);
}

// Function to return the last element of the list
t_list *ft_lstlast(t_list *head)
{
    t_list *tmp = head;

    if (tmp == NULL)
        return (NULL);

    while (tmp)
    {
        tmp = tmp->next;
    }
    return (tmp);
}

// Function to add a new element to the back of the list
void ft_lstadd_back(t_list *stack, t_list *new)
{
    t_list *tmp;

	tmp = stack;
	while (tmp)
	{
		tmp = tmp->next;
	}
	tmp->next = new;
	printf("tmp->content = %s\n", tmp->content);
}

