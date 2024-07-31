#include "../header/minishell.h"

void	free_env(t_env *env_copy)
{
	while (env_copy)
	{
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
		free_tab(command->args);
		free_tab(command->envp);
		command = command->next;
	}
	free(command);
}
