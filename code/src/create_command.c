#include "../header/minishell.h"

t_cmd	*ft_new_command()
{
	t_cmd	*new;

	new = malloc(sizeof(t_cmd));
	if (!new)
		return (NULL);
    new->envp = NULL;
	new->next = NULL;
	return (new);
}

int		add_command(t_cmd **command)
{
	t_cmd	*new_command;
	t_cmd	*last;

	new_command = ft_new_command();
	if (!new_command)
		return (1);
	if (*command == NULL)
	{
		*command = new_command;
		return (0);
	}
	last = *command;
	while (last->next)
		last = last->next;
	last->next = new_command;
	return (0);
}

int		create_multiple_command(t_cmd **command, int number_command)
{
	int		count_command;

	count_command = 0;
	while (count_command != number_command)
	{
		if (add_command(command) == 1)
			return (1);
		count_command++;
	}
	return (0);
}

t_cmd	*create_cmd(t_list *list)
{
	t_cmd 	*command;
	t_list	*tmp;
	int		number_command;

	command = NULL;
	number_command = (get_number_pipe(list) + 1);
	if (number_command != 1)
	{
		if (create_multiple_command(&command, number_command) == 1)
			return (NULL);
	}
	else
	{
		command  = ft_new_command();
		if (!command)
			return (NULL);
	}
	tmp = list;
	while (tmp)
	{
		tmp->read = 1;
		tmp = tmp->next;
	}
	return (command);
}