/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abentaye <abentaye@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 22:10:49 by abentaye          #+#    #+#             */
/*   Updated: 2024/05/13 10:50:21 by abentaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

// Need to implement functions that reads the input from the user then check if 
//the input is valid
// temporary function to exit the shell
void	exit_shell(char *input)
{
	if (strcmp(input, "exit") == 0)
	{
		printf("Exiting minishell\n");
		exit(0);
	}
}

// This function is going to catch the input from the user
char	*catch_input(char *prompt)
{
	char	*input;

	input = readline(prompt);
	if (!input)
		return (NULL);
	return (input);
}
// This function is going to launch the prompt and wait for the user to input a command
int prompt(void)
{
	char *input;
	
	while (1)
	{
		input = readline("minishell$ ");
		if (!input)
			break;
		exit_shell(input);
		printf("You entered: %s\n", input);
	}
	return (0);
}
