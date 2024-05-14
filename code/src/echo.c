#include "../header/minishell.h"

void	echo(char *str, int fd, int flag)
{
	ft_putstr_fd(str, fd);
	if (flag == 1)
		return ;
	else
		write(fd, "\n", 1);
}
