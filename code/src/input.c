/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abentaye <abentaye@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 20:13:35 by abentaye          #+#    #+#             */
/*   Updated: 2024/07/12 18:48:28 by abentaye         ###   ########.fr       */
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

//this function will turn a str into a list
t_list	*input_to_list(t_input *entry)
{
	char	**splinput;
	int		i;
	t_list	*new;

	splinput = ft_split(entry->line, ' ');
	i = 0;
	// PARSE THE INPUT AND ADD IT TO THE LIST
	while (splinput[i])
	{
		new = ft_lstnew(splinput[i]);
		printf("new -> content = %s\n", new->content);
		ft_lstadd_back(&entry->list, new);
		i++;
	}
	read_list(entry->list);
	free(splinput);
	return (entry->list);
}

//This function will loop and free the list
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

