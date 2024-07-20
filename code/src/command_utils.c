#include "../header/minishell.h"

int		get_number_command(t_cmd *cmd)
{
	t_cmd	*tmp;
	int		number_of_command;

	number_of_command = 0;
	tmp = cmd;
	while (tmp)
	{
		tmp = tmp->next;
		number_of_command++;
	}
	return (number_of_command);
}
