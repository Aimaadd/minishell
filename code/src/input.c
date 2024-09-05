/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abentaye <abentaye@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 20:13:35 by abentaye          #+#    #+#             */
/*   Updated: 2024/09/05 10:34:13 by abentaye         ###   ########.fr       */
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

int	counting_quotes(char *line)
{
	int	i;
	int	quotes_counter;

	quotes_counter = 0;
	i = 0;
	while(line[i])
	{
		if (line[i] == '\'' || line[i] == '\"')
			quotes_counter++;
		i++;	
	}
	return (quotes_counter);
}

char	*sort_quotes(char *line)
{
	int	i;
	int	first_quote;
	int	second_quote;
	int	quotes_counter;

	i = 0;
	first_quote = 0;
	second_quote = 0;
	quotes_counter = counting_quotes(line);
	if (quotes_counter % 2 != 0)
		return (NULL);
	while(line[i])
	{
		if (line[i] == '\'' || line[i] == '\"')
		{
			first_quote = i;
			while(line[i])
			{
				if (line[i] == '\'' || line[i] == '\"')
					second_quote = i;
				i++;
			}
		}
		i++;
	}
	return (NULL);
}

//this function will turn a str into a list
t_list	*input_to_list(t_input *entry)
{
	char	**splinput;
	int		i;
	
	splinput = NULL;
	i = 0;
	sort_quotes(entry->line);
	if (counting_quotes(entry->line) != 0)
	{
		while (entry->line[i])
		{
			if (entry->line[i] == '\"')
				splinput = ft_split(entry->line, '\"');
			else if (entry->line[i] == '\'')
				splinput = ft_split(entry->line, '\'');
			i++;
		}
	}
	else 
		splinput = ft_split(entry->line, ' ');
	entry->list = array_to_list(splinput);
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
