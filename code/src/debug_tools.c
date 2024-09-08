/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abentaye <abentaye@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 14:26:36 by abentaye          #+#    #+#             */
/*   Updated: 2024/09/08 15:47:35 by abentaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

// int	exit_status(t_input *entry)
// {
// 	if (ft_strncmp(entry->list->content, "$?", ft_strlen(entry->list->content))
// 		== 0)
// 		{
// 		    free(entry->list->content);
// 		    entry->list->content = ft_itoa(entry->ret_val);
// 		    return (ft_atoi(entry->list->content));
// 		}
// 		return (0);
// }
// void	printlist(t_list *list)
// {
// 	t_list	*tmp;
// 	int		counter;

// 	counter = 0;
// 	tmp = list;
// 	while (tmp)
// 	{
// 		printf("node[%d] : %s\n", counter++, tmp->content);
// 		tmp = tmp->next;
// 	}
// }

// void	printenv(t_env *env)
// {
// 	t_env	*tmp;
// 	int		counter;

// 	counter = 0;
// 	tmp = env;
// 	while (tmp)
// 	{
// 		printf("node[%d] : %s\n", counter++, tmp->variable);
// 		tmp = tmp->next;
// 	}
// }

// void	printab(char **str)
// {
// 	int	i;

// 	i = -1;
// 	while (str[++i])
// 		printf("printab [%d] : %s\n", i, str[i]);
// 	return ;
// }

// void	printcmd(t_cmd *cmd)
// {
// 	t_cmd	*tmp;
// 	int		i;

// 	tmp = cmd;
// 	while (tmp)
// 	{
// 		printf("Command:\n");
// 		printf("  File: %s\n", tmp->file);
// 		printf("  Type File: %d\n", tmp->type_file);
// 		printf("  Args:\n");
// 		for (i = 0; tmp->args && tmp->args[i]; i++)
// 		{
// 			printf("	[%d]: %s\n", i, tmp->args[i]);
// 		}
// 		// printf("  Envp:\n");
// 		// for (i = 0; tmp->envp && tmp->envp[i]; i++)
// 		// {
// 		//     printf("    [%d]: %s\n", i, tmp->envp[i]);
// 		// }
// 		// printf("  Env Copy:\n");
// 		// printenv(tmp->env_copy);
// 		tmp = tmp->next;
// 	}
// }