#include "../header/minishell.h"

char	*find_binary(char *binary, char *path)
{
	char	**tab_path;
	char	*tmp;
	int		count;

	tab_path = ft_split(path, ':');
	if (!tab_path)
		return (NULL);
	binary = ft_strjoin("/", binary);
	count = 0;
	while (tab_path[count])
	{
		tmp = ft_strjoin(tab_path[count], binary);
		if (access(tmp, X_OK) == 0)
			return (tmp);
		free(tmp);
		count++;
	}
	return (NULL);
}

int		simple_command(t_cmd *cmd)
{
	char	*path;
	pid_t	pid;
	int		status;

	path = ft_getenv(cmd->lst_env, "PATH");
	if (!path)
		return (1);
	cmd->args[0] = find_binary(cmd->args[0], path);
	if (cmd->args[0] == NULL)
		return (1);
	pid = fork();
	if (pid == -1)
		return (1);
	else if (pid == 0)
		if (execve(cmd->args[0], cmd->args, cmd->env_copy))
			exit(0);
	waitpid(pid, &status, 0);
	return (0);
}

int		pipe_command(t_cmd *cmd)
{
	int		x;
	int		numbers_command;
	t_list	*tmp;

	x = 0;
	tmp = cmd->list;
	while(numbers_command != cmd->numbers_pipe)
	{
		while(tmp->type != PIPE)
		{
			x++;
			tmp = tmp->next;
		}
		cmd->args = malloc(sizeof(char *) * (x + 1));
		if (!cmd->args)
			return (1);
		create_args(cmd, cmd->list, x);
		x++;
		//free_tab();
	}
	return (0);
}
