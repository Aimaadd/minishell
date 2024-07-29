/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abentaye <abentaye@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 12:39:47 by abentaye          #+#    #+#             */
/*   Updated: 2024/07/28 15:59:04 by abentaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

// int redirection(t_list *list) {
//     t_list *tmp = list;
//     int saved_stdout = dup(STDOUT_FILENO);  // Save the original stdout

//     while (tmp != NULL && tmp->next != NULL) {
//         printf("Processing: %s\n", tmp->content);
//         if (strcmp(tmp->content, ">") == 0) {
//             printf("Redirecting output to: %s\n", tmp->next->content);
//             if (dup_and_close(tmp->next->content) != 0) {
//                 dup2(saved_stdout, STDOUT_FILENO);  // Restore the original stdout on error
//                 close(saved_stdout);
//                 return 1;
//             }
//         }
//         tmp = tmp->next->next; // Move to the next pair
//     }

//     dup2(saved_stdout, STDOUT_FILENO);  // Restore the original stdout
//     close(saved_stdout);
//     return 0;
// }

// int dup_and_close(char *filename) {
//     int fd;
//     int duptest;

//     printf("Opening file: %s\n", filename);
//     fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
//     if (fd < 0) {
//         perror("open");
//         return 1;
//     }
//     printf("Duplicating fd: %d\n", fd);
//     duptest = dup2(fd, STDOUT_FILENO);
//     if (duptest < 0) {
//         perror("dup2");
//         close(fd);
//         return 1;
//     }
//     close(fd);
//     return 0;
// }

// void execute_command(t_list *cmd_list) {
//     // Separate command and arguments from redirections
//     t_list *tmp = cmd_list;
//     char *args[100];  // Assuming a maximum of 100 arguments
//     int i = 0;

//     // Extract command and arguments until a redirection operator is found
//     while (tmp != NULL && strcmp(tmp->content, ">") != 0) {
//         args[i++] = tmp->content;
//         tmp = tmp->next;
//     }
//     args[i] = NULL;

//     pid_t pid = fork();

//     if (pid == 0) {  // Child process
//         // Handle redirections in the child process
//         if (tmp != NULL) {
//             if (redirection(tmp) != 0) {
//                 fprintf(stderr, "Failed to handle redirections\n");
//                 exit(EXIT_FAILURE);
//             }
//         }
//         // Execute the command
//         if (execvp(args[0], args) == -1) {
//             perror("execvp");
//         }
//         exit(EXIT_FAILURE);
//     } else if (pid < 0) {
//         perror("fork");
//     } else {  // Parent process
//         int status;
//         waitpid(pid, &status, 0);
//     }
// }
void error_exit(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

void redirection(t_list *list) {
    int fd;
    pid_t pid;

    // Move to the next node to get the file name
    if (list->next == NULL || list->next->content == NULL) {
        fprintf(stderr, "Syntax error: no file provided for redirection\n");
        exit(EXIT_FAILURE);
    }
    char *filename = list->next->content;

    // Backtrack to find the start of the command
    t_list *cmd_node = list;
    while (cmd_node->next != NULL && cmd_node->next->content != NULL && strcmp(cmd_node->next->content, ">") != 0) {
        cmd_node = cmd_node->next;
    }
    if (cmd_node->content == NULL) {
        fprintf(stderr, "Syntax error: no command provided\n");
        exit(EXIT_FAILURE);
    }

    // Open the file for writing
    fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0644);
    if (fd == -1) {
        error_exit("open");
    }

    // Fork and execute the command
    pid = fork();
    if (pid == -1) {
        error_exit("fork");
    }

    if (pid == 0) {
        // Child process
        if (dup2(fd, STDOUT_FILENO) == -1) {
            error_exit("dup2");
        }
        close(fd);

        // Prepare the command arguments
        t_list *tmp = list;
        int i = 0;
        while (tmp != NULL && strcmp(tmp->content, ">") != 0) {
            i++;
            tmp = tmp->next;
        }
        char *args[i + 1];
        tmp = cmd_node;
        for (int j = 0; j < i; j++) {
            args[j] = tmp->content;
            tmp = tmp->next;
        }
        args[i] = NULL;

        if (execve(args[0], args, NULL) == -1) {
            error_exit("execve");
        }
    } else {
        // Parent process
        close(fd);
        waitpid(pid, NULL, 0);
    }
}