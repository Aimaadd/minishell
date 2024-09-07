/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_handling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abentaye <abentaye@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 18:56:38 by abentaye          #+#    #+#             */
/*   Updated: 2024/09/07 20:45:06 by abentaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

void	empty_node(t_list *list)
{
	t_list	*tmp;
	t_list	*next;

	tmp = list;
	while (tmp != NULL)
	{
		next = tmp->next;
		free(tmp);
		tmp = next;
	}
	return ;
}

void	free_list(t_list *list)
{
	t_list	*tmp;

	while (list)
	{
		tmp = list;
		list = list->next;
		free(tmp->content);
		free(tmp);
	}
}

//this function will turn a str into a list
void	add_to_list(t_list **list, char *content)
{
	t_list	*new;
	t_list	*temp;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return ;
	new->content = strdup(content);
	new->next = NULL;
	if (!*list)
		*list = new;
	else
	{
		temp = *list;
		while (temp->next)
			temp = temp->next;
		temp->next = new;
	}
}
int get_size_list(t_list *list)
{
    int size = 0;
    t_list *tmp = list;

    while (tmp)
    {
        size++;
        tmp = tmp->next;
    }
    return size;
}
