#include "../header/minishell.h"

int		get_size_list(t_list *list)
{
	t_list	*tmp;
	int		len;

	len = 0;
	tmp = list;
	while(tmp)
	{
		tmp = tmp->next;
		len++;	
	}
	return (len);
}

void	create_args(t_cmd *cmd, t_list	*list)
{
	t_list	*tmp;
	int		count;

	count = 0;
	tmp = list;
	while(tmp)
	{
		cmd->args[count] = tmp->content;
		count++;
		tmp = tmp->next;
	}
	cmd->args[count] = NULL;
	return ;
}

int		check_if_pipe(t_list *list)
{
	t_list	*tmp;
	int 	count;

	count = 0;
	tmp = list;
	while (tmp)
	{
		printf("type = %d\n", tmp->type);
		if (tmp->type == 5)
			count++;
		tmp = tmp->next;	
	}
	return (count);
}
