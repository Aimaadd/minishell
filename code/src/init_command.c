/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abentaye <abentaye@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 15:29:33 by abentaye          #+#    #+#             */
/*   Updated: 2024/09/12 18:47:54 by abentaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

int	add_args_bis(t_list **tmp_list, t_cmd **tmp_cmd)
{
	if ((*tmp_list)->type == PIPE)
	{
		(*tmp_list)->second_read = 0;
		return (0);
	}
	if ((*tmp_list)->type == REDIRECTION || (*tmp_list)->type == APPEND)
	{
		if ((*tmp_list)->type == REDIRECTION)
			(*tmp_cmd)->type_file = 1;
		else
			(*tmp_cmd)->type_file = 2;
		(*tmp_cmd)->file = (*tmp_list)->next->content;
		(*tmp_list)->second_read = 0;
		if (!(*tmp_list)->next->next)
			return (0);
		(*tmp_list) = (*tmp_list)->next;
		(*tmp_list)->second_read = 0;
		(*tmp_list) = (*tmp_list)->next;
	}
	return (1);
}

int add_args_sub_loop(t_list **tmp_list, t_cmd **cmd, int *x)
{
    // Ensure tmp_list and cmd are not NULL
    if (!tmp_list || !*tmp_list || !cmd || !*cmd || !x)
        return 1;

    // Ensure cmd->args is allocated and x is within bounds
    if (!(*cmd)->args || *x < 0)
        return 1;

    // Example operation: copying content from tmp_list to cmd->args
    while (*tmp_list && (*tmp_list)->type != PIPE)
    {
        if ((*tmp_list)->type != REDIRECTION && (*tmp_list)->type != APPEND)
        {
            (*cmd)->args[*x] = strdup((*tmp_list)->content);
            if (!(*cmd)->args[*x])
                return 1; // Memory allocation failed
            (*x)++;
        }
        *tmp_list = (*tmp_list)->next;
    }

    // Null-terminate the args array
    (*cmd)->args[*x] = NULL;

    // Move to the next command if a pipe character is encountered
    if (*tmp_list && (*tmp_list)->type == PIPE)
        *tmp_list = (*tmp_list)->next;

    return 0;
}

int add_args(void)
{
    t_list *tmp_list;
    t_cmd *tmp_cmd;
    int len_command;
    int x;

    tmp_list = g_ms->list;
    tmp_cmd = g_ms->cmd;
    while (tmp_cmd)
    {
        x = 0;
        len_command = get_size_command(tmp_list);
        tmp_cmd->args = malloc(sizeof(char *) * (len_command + 1));
        if (!tmp_cmd->args)
            return (1);
        for (int i = 0; i <= len_command; i++)
            tmp_cmd->args[i] = NULL;
        if (add_args_sub_loop(&tmp_list, &tmp_cmd, &x))
            return (1);
        tmp_cmd = tmp_cmd->next;
    }
    return (0);
}
