#include "../header/minishell.h"

static t_data_multiple	*init_data_multiple(t_cmd *command)
{
	t_data_multiple	*data;

	data = malloc(sizeof(t_data_multiple *));
	if (!data)
		return (NULL);
	data->number_of_command = get_number_command(command);
	data->count_command = 0;
	data->count_pid = 0;
	return (data);
}


int		multiple_command(t_cmd *command)
{
	t_data_multiple	*data;
	pid_t			*pid;
	t_cmd			*tmp_command;
	int				fd[2];
	int				last_fd;

	data = init_data_multiple(command);
	if (!data)
		return (1);
	pid = (pid_t *)malloc(sizeof(pid_t) * data->number_of_command);
	if (!pid)
		return (1);
	tmp_command = command;
	while (tmp_command)
	{
		if (tmp_command->next)
			if (pipe(fd) == -1)
				return (1);
		pid[data->count_command] = fork();
		if (pid[data->count_command] == -1)
			exit (1);
		if (pid[data->count_command] == 0)
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
			// command redirection
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
		data->count_command++;
		tmp_command = tmp_command->next;	
	}
	while (data->count_pid < data->count_command)
	{
		waitpid(pid[data->count_pid], 0, 0);
		data->count_pid++;
	}
	return (0);
}
