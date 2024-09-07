/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abentaye <abentaye@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 20:13:35 by abentaye          #+#    #+#             */
/*   Updated: 2024/09/07 19:00:37 by abentaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

// this function creates a new node to my list
void	new_node(t_list **list, char *content)
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

char	*get_next_token(char **input)
{
	char	*start;
	char	quote_char;

	while (ft_isspace(**input))
		(*input)++;
	if (**input == '\'' || **input == '\"')
	{
		quote_char = *(*input)++;
		start = *input;
		while (**input && **input != quote_char)
			(*input)++;
	}
	else
	{
		start = *input;
		while (**input && !ft_isspace(**input) && **input
			!= '\'' && **input != '\"')
			(*input)++;
	}
	return (strndup(start, *input - start));
}

t_list	*input_to_list(char *input)
{
	t_list	*list;
	char	*token;

	list = NULL;
	while (*input)
	{
		token = get_next_token(&input);
		if (*input == '\'' || *input == '\"')
			input++;
		add_to_list(&list, token);
		free(token);
	}
	return (list);
}
