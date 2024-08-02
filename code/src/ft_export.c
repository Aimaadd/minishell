/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abentaye <abentaye@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 15:31:19 by abentaye          #+#    #+#             */
/*   Updated: 2024/08/02 15:31:23 by abentaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

static void	swap(t_env *element)
{
	char	*tmp_variable;
	char	*tmp_value;

	tmp_variable = element->variable;
	tmp_value = element->value;
	element->variable = element->next->variable;
	element->value = element->next->value;
	element->next->variable = tmp_variable;
	element->next->value = tmp_value;
}

static void	bubble_sort(t_env *env)
{
	int		swapped;
	int		len;
	t_env	*element;
	t_env	*checked;

	if (!env)
		return ;
	swapped = 1;
	checked = NULL;
	while (swapped)
	{
		swapped = 0;
		element = env;
		while (element->next != checked)
		{
			len = check_size(element->variable, element->next->variable);
			if (ft_strncmp(element->variable, element->next->variable, len) > 0)
			{
				swap(element);
				swapped = 1;
			}
			element = element->next;
		}
		checked = element;
	}
}

static void	print_element(t_env **copy_env)
{
	t_env	*temp;

	temp = *copy_env;
	bubble_sort(temp);
	while (temp)
	{
		if (ft_strlen(temp->value) == 0)
			printf("declare -x %s\n", temp->variable);
		else
			printf("declare -x %s=%s\n", temp->variable, temp->value);
		temp = temp->next;
	}
}

void	ft_export(char *input, t_env **copy_env)
{
	printf("input = %s\n", input);
	if (!input || input[0] == 0)
		print_element(copy_env);
	else
		add_element(copy_env, input);
	return ;
}
