#include "../header/minishell.h"

static void	delete_variable(char *variable, t_env *copy_env)
{
	t_env	*tmp;
	t_env	*variable_before;
	t_env	*variable_after;
	int		len;
	int		check;

	tmp = copy_env;
	while (tmp)
	{
		len = check_size(variable, tmp->variable);
		check = ft_strncmp(variable, tmp->variable, len);
		if (check == 0)
		{
			variable_after = tmp->next;
			break;
		}
		variable_before = tmp;
		tmp = tmp->next;
	}
	variable_before->next = variable_after;
	if (tmp != NULL)
		free(tmp);
}

void	ft_unset(char *variable, t_env **copy_env)
{
	if (variable == NULL || variable[0] == 0)
		return ;
	if (ft_getenv(*copy_env, variable))
		delete_variable(variable, *copy_env);
}
