#include "../header/minishell.h"

void	printlist(t_list *list)
{
	t_list	*tmp = NULL;
	int		counter = 0;
	tmp = list;
	while (tmp)
	{
		printf("node[%d] : %s\n", counter++, tmp->content);
		tmp = tmp->next;
	}
}

void	printenv(t_env *env)
{
	t_env	*tmp = NULL;
	int		counter = 0;
	tmp = env;
	while (tmp)
	{
		printf("node[%d] : %s\n", counter++, tmp->variable);
		tmp = tmp->next;
	}
}

void	printab(char **str)
{
	int	i;

	i = -1;
	while (str[++i])
		printf("printab [%d] : %s\n",i,str[i]);
	return ;
}
