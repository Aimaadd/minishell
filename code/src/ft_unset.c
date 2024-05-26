#include "../header/minishell.h"

void	delete_variable(char *variable, t_env *copy_env)
{
	t_env	tmp;
	t_env	tmp2;
	int		len;

	tmp = copy_env;
	while (tmp)
	{
		len = check_size(tmp->variable, tmp->next->variable);
		if (ft_strncmp(tmp->variable, tmp->next->variable, len) = 0)
			break ;
		tmp = tmp->next;
	}
	tmp2 = tmp->next;
}

void	ft_unset(char *variable, t_env **copy_env)
{
	if (variable == NULL || variable[0] == 0)
		return ;
	if (ft_getenv(*copy_env, variable))
		delete_variable();
}
