#include "../header/minishell.h"

char    *find_binary(char *bin, char *path)
{
    char    **new_path;
    char    *path_bin;
    int     x;

    bin = ft_strjoin("/", bin);
    if (!bin)
        return (NULL);
    new_path = ft_split(path, ':');
    if (!new_path)
        return (NULL);
    x = 0;
    while (new_path[x])
    {
        path_bin = ft_strjoin(new_path[x], bin);
        if (access(path_bin, X_OK) == 0)
            return (path_bin);
        free(path_bin);
        x++;
    }
    return (NULL);
}

int     simple_command(t_cmd *command)
{
    pid_t   pid;
    int     status;

    command->args[0] = find_binary(command->args[0], ft_getenv(command->env_copy, "PATH"));
    if (!command->args[0])
        return (1);
    pid = fork();
    if (pid == 1)
        return (1);
    else if (pid == 0)
    {
        execve(command->args[0], command->args, command->envp);
        exit (0);
    }
    waitpid(pid, &status, 0);
    return (0);
}

int		multiple_command(t_cmd *command)
{
	pid_t	*pid;
	t_cmd	*tmp_command;
	int		number_of_command;
	int		count_command;
	int		fd[2];
	int		last_fd;

	number_of_command = get_number_command(command);
	pid = (pid_t *)malloc(sizeof(pid_t) * number_of_command);
	if (!pid)
		return (1);
	tmp_command = command;
	count_command = 0;
	while (tmp_command)
	{
		if (tmp_command->next)
			if (pipe(fd) == -1)
				return (1);
		pid[count_command] = fork();
		if (pid[count_command] == -1)
			exit (1);
		if (pid[count_command] == 0)
		{
			if (last_fd != -1)
			{
				dup2(last_fd, STDIN_FILENO);
				close(last_fd);
			}
			if (tmp_command->next)
			{
				close(fd[0]);
				dup2(fd[1], STDOUT_FILENO);
				close(fd[1]);
			}
			simple_command(tmp_command);
			exit (0);
		}
       if (last_fd != -1)
		{
            close(last_fd);
        }
        if (tmp_command->next)
		{
            close(fd[1]);
            last_fd = fd[0];
        }
		count_command++;
		tmp_command = tmp_command->next;	
	}
	int x = 0;
	while (x < count_command)
	{
		waitpid(pid[x], 0, 0);
		x++;
	}
	return (0);
}
