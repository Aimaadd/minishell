#include "../header/minishell.h"

void	update_envp(t_env *env_copy, char **envp)
{
	free_tab(envp);
	envp = conv_tab_env(env_copy);
}

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

	if (check_builtin(command) == 0)
	{
		update_envp(command->env_copy, command->envp);
		return (0);
	}
    command->args[0] = find_binary(command->args[0], ft_getenv(command->env_copy, "PATH"));
    if (!command->args[0])
        return (1);
    pid = fork();
    if (pid == 1)
        return (1);
    else if (pid == 0)
    {
		if (command->file)
			redirection(command->file);
        execve(command->args[0], command->args, command->envp);
        exit (0);
    }
    waitpid(pid, &status, 0);
    return (0);
}
