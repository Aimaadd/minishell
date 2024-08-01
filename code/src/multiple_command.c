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
	data->last_fd = -1;
	return (data);
}

static void		ft_waitpid(t_data_multiple *data, pid_t *pid)
{
	while (data->count_pid < data->count_command)
	{
		waitpid(pid[data->count_pid], 0, 0);
		data->count_pid++;
	}
}

static void		run_child(pid_t *pid, t_data_multiple *data, int *fd, t_cmd *tmp_command)
{
	pid[data->count_command] = fork();
	if (pid[data->count_command] == -1)
		exit (1);
	if (pid[data->count_command] == 0)
	{
		if (data->last_fd != -1)
		{
			dup2(data->last_fd, STDIN_FILENO);
			close(data->last_fd);
		}
		if (tmp_command->next)
		{
			close(fd[0]);
			dup2(fd[1], STDOUT_FILENO);
			close(fd[1]);
		}
		// command redirection
		simple_command(tmp_command);
		exit (0);
	}
}

static void	check_fd(t_data_multiple *data, int *fd, t_cmd *tmp_command)
{
	if (data->last_fd != -1)
	{
		close(data->last_fd);
	}
	if (tmp_command->next)
	{
		close(fd[1]);
		data->last_fd = fd[0];
	}
}

int		multiple_command(t_cmd *command)
{
	t_data_multiple	*data;
	pid_t			*pid;
	t_cmd			*tmp_command;
	int				fd[2];

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
		run_child(pid, data, fd, tmp_command);
		check_fd(data, fd, tmp_command);
		data->count_command++;
		tmp_command = tmp_command->next;	
	}
	ft_waitpid(data, pid);
	free(data);
	return (0);
}