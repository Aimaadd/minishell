/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_next_cmd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abentaye <abentaye@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 16:38:10 by abentaye          #+#    #+#             */
/*   Updated: 2024/09/15 17:09:55 by abentaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	close_all_pipes(t_cmd *cmd, int *pipereadfd)
{
	safe_close(cmd->pipein);
	safe_close(cmd->pipein + 1);
	safe_close(cmd->pipeout);
	safe_close(cmd->pipeout + 1);
	safe_close(pipereadfd);
}

static void	init_cmd(t_cmd *cmd)
{
	ft_memset(cmd, 0, sizeof(t_cmd));
	cmd->pipeout[0] = -1;
	cmd->pipeout[1] = -1;
	cmd->pipein[0] = -1;
	cmd->pipein[1] = -1;
}

// rigth_path should return the executable directly if no good path found.
// -> add gc.h to libft
void	child_execution(t_cmd *cmd, int is_last_cmd, int pipereadfd)
{
	char	*executable;
	int		tfree;
	int		err;

	executable = NULL;
	setup_child_pipes(cmd, is_last_cmd, &pipereadfd);
	if (is_builtin(cmd->executable))
		exec_builtin(cmd->arg_len, cmd->args);
	if (!(*(cmd->executable) == '/' || *(cmd->executable) == '.'))
		executable = right_path(cmd->executable, g_ms.envs);
	tfree = 1;
	if (executable == NULL)
	{
		executable = cmd->executable;
		tfree = 0;
	}
	execve(executable, cmd->args, g_ms.envs);
	err = errno;
	if (err == ENOENT)
		print_error("minishell", cmd->executable, "command not found");
	if (tfree != 0)
		free(executable);
	clean_exit(err);
}

static void	redirout(t_cmd *cmd, int *pipereadfd, int depth)
{
	int	err;

	err = pipe_tofile(cmd->pipeout[0], cmd->redirout_file, cmd->redirout_type);
	safe_close(cmd->pipeout);
	if (err == SOFTFAIL_ERROR)
	{
		kill(g_ms.pids[depth], SIGKILL);
		close_all_pipes(cmd, pipereadfd);
		print_error("minishell", strerror(errno), cmd->redirout_file);
	}
}

void	exec_next_cmd(t_token *token, int pipereadfd, int depth)
{
	t_cmd	cmd;
	int		err;

	if (token == NULL)
		return ;
	init_cmd(&cmd);
	err = setup_next_cmd(&cmd, &token);
	if (err)
	{
		handle_setup_error(err, &cmd, &pipereadfd, token, depth);
		return ;
	}
	handle_fork(&cmd, pipereadfd, depth, token);
	unsetup_child_pipes(&cmd, &pipereadfd);
	if (cmd.redirout_type != 0)
		redirout(&cmd, &pipereadfd, depth);
	if (token == NULL)
		return ;
	exec_next_cmd(token, cmd.pipeout[0], depth + 1);
}
