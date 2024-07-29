#include "../header/minishell.h"

int		check_parametre(char **args)
{
	char	**tmp;

	tmp = args;
	if (ft_strncmp(tmp[1], "-n", check_max_len(tmp[1], "-n")) == 0)
			return (0);
	return (1);
}

void	ft_echo(t_cmd *command)
{
	int		flag;
	int		x;
	int		y;
	char	**args;

	args = command->args;
	flag = 0;
	x = 0;
	y = 0;
	if (check_parametre(command->args) == 1)
		flag = 1;
	if (flag == 0)
		x = 2;
	else
		x = 1;
	while(args[x])
	{
		y = 0;
		while (args[x][y])
		{
			write(1, &args[x][y], 1);
			y++;
		}
		x++;
	}
	if (flag == 1)
		write(1, "\n", 2);
}
