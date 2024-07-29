#include "../header/minishell.h"

int     child_proccess(t_cmd *cmd)
{
    if (!dup2(cmd->fd[0], STDIN_FILENO))
        return (1);
    if (!dup2(cmd->fd[1], STDOUT_FILENO))
        return (1);
    close(cmd->fd[0]);
    return (0);
}