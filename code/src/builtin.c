#include "../header/minishell.h"

int		check_max_len(char *s1, char *s2)
{
	int		len_s1;
	int		len_s2;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	if (len_s1 < len_s2)
		return (len_s2);
	else
		return (len_s1);
}

int		ft_builtin_compare(char *command_user, char *builtin)
{
	int		len_max;
	int		check;

	len_max = check_max_len(command_user, builtin);
	check = ft_strncmp(command_user, builtin, len_max);
	if (check != 0)
		return (1);
	return (check);
}

int		check_builtin(t_cmd *command)
{
	char 	*is_builtin;

	is_builtin = command->args[0];
	if (ft_builtin_compare(is_builtin, "echo") == 0)
	{
		ft_echo(command);
		return (0);
	}
	if (ft_builtin_compare(is_builtin, "cd") == 0)	
	{
		ft_cd(command->args[1], command->env_copy);
		return (0);
	}
	/* if (ft_builtin_compare(is_builtin, "pwd") == 0) */	
	/* 	ft_pwd(); */
	/* if (ft_builtin_compare(is_builtin, "export") == 0) */	
	/* 	ft_export(); */
	/* if (ft_builtin_compare(is_builtin, "unset") == 0) */	
	/* 	ft_unset(); */
	/* if (ft_builtin_compare(is_builtin, "env") == 0) */	
	/* 	ft_env(); */
	/* if (ft_builtin_compare(is_builtin, "exit") == 0) */	
	/* 	ft_exit(); */
	return (1);
}
