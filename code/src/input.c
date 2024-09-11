/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abentaye <abentaye@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 20:13:35 by abentaye          #+#    #+#             */
/*   Updated: 2024/09/11 19:47:28 by abentaye         ###   ########.fr       */
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
t_list	*input_to_list()
{
	char	**splinput;

	splinput = ft_split(g_ms->line, ' ');
	g_ms->list = array_to_list(splinput);
	printab(splinput);
	free(splinput);
	return (g_ms->list);
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
