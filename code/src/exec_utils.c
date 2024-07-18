#include "../header/minishell.h"

int     get_number_pipe(t_list *list)
{
    int     count_pipe;
    t_list  *tmp;

    count_pipe = 0;
    tmp = list;
    while (tmp)
    {
        if (tmp->type == PIPE)
            count_pipe++;
        tmp = tmp->next;
    }
    return (count_pipe);
}

void    free_args(char **args)
{
    int x;

    x = 0;
    while (args[x])
    {
        free(args[x]);
        x++;
    }
    free(args);
}