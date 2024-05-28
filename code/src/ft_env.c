#include "../header/minishell.h"

void	ft_env(t_env *env)
{
	t_env	*env_tmp;

	env_tmp = env;
	while (env_tmp)
	{
		printf("%s=%s\n", env_tmp->variable, env_tmp->value);
		env_tmp = env_tmp->next;
	}
}
