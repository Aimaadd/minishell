/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abentaye <abentaye@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 22:10:49 by abentaye          #+#    #+#             */
/*   Updated: 2024/08/02 15:16:34 by abentaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

// Need to implement functions that reads the input from the user then check if 
//the input is valid
// temporary function to exit the shell
void	exit_shell(char *input)
{
	if (ft_strncmp(input, "exit", 4) == 0)
	{
		printf("Exiting minishell\n");
		exit(0);
	}
}

// // This function is going to catch the input from the user
char	*catch_input(char *input)
{
	exit_shell(input);
	if (!input)
		return (NULL);
	return (input);
}

// This function is going to launch the prompt and wait user to input a command
char	*prompt(void)
{
	char	*input;

	while (1)
	{
		input = readline("minishell$ ");
		if (!input)
			break ;
		catch_input(input);
		if (!input)
			continue ;
	}
	return (input);
}
