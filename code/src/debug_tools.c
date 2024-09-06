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

void printcmd(t_cmd *cmd)
{
    t_cmd *tmp = cmd;
    int i;

    while (tmp)
    {
        printf("Command:\n");
        printf("  File: %s\n", tmp->file);
        printf("  Type File: %d\n", tmp->type_file);
        printf("  Args:\n");
        for (i = 0; tmp->args && tmp->args[i]; i++)
        {
            printf("    [%d]: %s\n", i, tmp->args[i]);
        }
        // printf("  Envp:\n");
        // for (i = 0; tmp->envp && tmp->envp[i]; i++)
        // {
        //     printf("    [%d]: %s\n", i, tmp->envp[i]);
        // }
        printf("  Env Copy:\n");
        // printenv(tmp->env_copy);
        tmp = tmp->next;
    }
}