#include "../header/minishell.h"

void	ft_echo(char *str, int parametre, int fd)
{
	ft_putstr_fd(str, fd);
	if (parametre == 1)
		return ;
	else
		write(fd, "\n", 1);
}