/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abentaye <abentaye@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 15:31:09 by abentaye          #+#    #+#             */
/*   Updated: 2024/08/02 15:31:10 by abentaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

void	free_env(t_env *env_copy)
{
	while (env_copy)
	{
		if (env_copy->variable)
			free(env_copy->variable);
		free(env_copy->value);
		env_copy = env_copy->next;
	}
	free(env_copy);
}

void	free_command(t_cmd *command)
{
	while (command)
	{
		
		if (command->args)
			free_tab(command->args);
		if (command->envp)
			free_tab(command->envp);
		if (command->file)
			free(command->file);
		free_env(command->env_copy);
		command = command->next;
	}
	free(command);
}
