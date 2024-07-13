/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abentaye <abentaye@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 18:23:00 by abentaye          #+#    #+#             */
/*   Updated: 2024/07/13 16:25:54 by abentaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

t_input *init_input(void)
{
    t_input *entry = malloc(sizeof(t_input));
    if (!entry)
        return NULL;
    entry->index = 0;
    entry->line = NULL;
    entry->env = NULL;
    entry->list = NULL;
    return entry;
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

void	ft_lstadd_back(t_list *stack, t_list *new)
{
	t_list	*tmp;

	if (stack == NULL)
		stack = new;
	else
	{
		tmp = stack;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
	}
	new->next = NULL;
	printf("Added element with content: %s\n", new->content);
}

