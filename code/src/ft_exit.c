#include "../header/minishell.h"

void	ft_exit(t_cmd *cmd)
{
	free_command(cmd);
	exit(1);
}
