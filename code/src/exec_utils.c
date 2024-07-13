#include "../header/minishell.h"

int		get_size_list(t_list *list)
{
	t_list	*tmp;
	int		len;

	len = 0;
	tmp = list;
	while(tmp)
	{
		printf("content : %s\n", tmp->content);
		tmp = tmp->next;
		len++;	
	}
	printf("len = %d\n", len);
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
