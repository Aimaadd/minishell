/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abentaye <abentaye@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 15:45:40 by abentaye          #+#    #+#             */
/*   Updated: 2024/06/13 10:24:26 by abentaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

//need a function to check all the fds

int	main(int argc, char **argv)
{
  pid_t pid;

  pid = fork();
  if (pid < 0)
  {  
    perror("Fork");
    exit (1);
  }
// if (pid == 0)
    printf("child pid = 0 : %d\n", getpid());
}
