/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abentaye <abentaye@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 18:23:00 by abentaye          #+#    #+#             */
/*   Updated: 2024/07/14 14:31:31 by abentaye         ###   ########.fr       */
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

t_list *ft_lstnew(void *content)
{
	t_list *new_node = (t_list *)malloc(sizeof(t_list));
	if (!new_node)
		return NULL;
	new_node->content = content;
	new_node->next = NULL;
	new_node->type = 0;
	return new_node;
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

void ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list *current;

	if (!lst || !new)
		return;

	if (*lst == NULL)
	{
		*lst = new;
	}
	else
	{
		current = *lst;
		while (current->next != NULL)
		{
			current = current->next;
		}
		current->next = new;
	}
}

t_list	*array_to_list(char **array)
{
	t_list	*list;
	t_list	*new_node;
	int		i = 0;

	list = NULL;
	while (array[i] != NULL)
	{
		new_node = ft_lstnew(array[i]);
		if (!new_node)
		{
			t_list *current = list;
			t_list *next;
			while (current != NULL)
			{
				next = current->next;
				free(current);
				current = next;
			}
			return (NULL);
		}
		ft_lstadd_back(&list, new_node);
		i++;
	}
	return list;
}
