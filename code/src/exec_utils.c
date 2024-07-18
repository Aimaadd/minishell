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

int     get_size_command(t_list *list)
{
    int         len_command;
    t_list      *tmp;

    len_command = 0;
    tmp = list;
    while(tmp)
    {
        if (tmp->read == 0)
            tmp = tmp->next;
        else
        {
            if (tmp->type == PIPE)
            {
                tmp->read = 0;
                return (len_command);
            }
            len_command++;
            tmp->read = 0;
            tmp = tmp->next;
        }
    }
    return (len_command);
}