/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abentaye <abentaye@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 20:13:35 by abentaye          #+#    #+#             */
/*   Updated: 2024/05/27 12:19:00 by abentaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

void	print_list(t_list *list)
{
	while (list)
	{
		if (list->content)
			printf("%s\n", list->content);
		list = list->next;
	}
}

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

	splinput = ft_split(entry->line, ' ');
	i = 0;
	while (splinput[i])
	{
		entry->list = new_node(&entry->list, splinput[i]);
		printf("entry->list->content[%i] = %s\n", i, entry->list->content);
		i++;
	}
	free(splinput);
	return (entry->list);
}

void	filling_loop(t_input *entry)
{
	while (entry->line)
	{
		input_to_list(entry);
	}
}
