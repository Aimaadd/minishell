#include "../header/minishell.h"

void	ft_pwd()
{
	char	*path;

	path = getcwd(0, 0);
	if (!path)
		perror("");
	else
		printf("%s\n", path);
	return ;
}
