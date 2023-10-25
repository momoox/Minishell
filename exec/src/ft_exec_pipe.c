/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_pipe.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momox <momox@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 02:47:43 by oliove            #+#    #+#             */
/*   Updated: 2023/10/25 22:52:16 by momox            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
on recois noeud par noeud :
	- data->exec->content
	- data->exec->token
	- data->env
les data que jai bessoin dans la struct
*/
#include "util_exec.h"
#include "minishell.h"

static int	ft_pipex2(t_data *data, int *fd_stdin, int *fd_stdout)
{
	int	cmd1;
	int	i;
	// int	fd[2];
	// (void)fd_stdin;
	// (void)fd_stdout;
    
	cmd1 = 1;
	i = 0;
    printf("ft_pipex2 == data->fd_in[%d] | fd_stdin == [%d] | fd_stdout == [%d] | cmd == [%d]\n",data->exec->fd_in, *fd_stdin, *fd_stdout ,cmd1);
	if (data->exec->stdin_st && data->list->token == REDIR_IN)
		*fd_stdin = file_o(data,data->exec->cmd[0], 0);
	if (data->exec->fd_in == -1)
		cmd1 = 0;
	if(data->exec->stdout_st && data->list->token ==  REDIR_OUT)
		*fd_stdout = file_o(data, data->exec->cmd[0], 1);
	if (!cmd1)
	{
		i++;
		pipe(fd_stdin);
        close(*fd_stdout);
		// data->exec->fd_in = fd[0];
		*fd_stdin = data->exec->fd_in;
	}
	return (i);
}


int ft_lstsize(t_list *list)
{
    int i;

    i = 0;
    while (list)
    {
        i++;
        list = list->next;
    }
    return (i);
}

void ft_pipe(t_data *data)
{
    int j;
    int fd_pipe[2];
    pid_t pid;

    // printf("exec : %d\n", data->nb_exec);
    j = 0;
    while (j < data->nb_exec)
    {
        if (j < data->nb_exec - 1)
        {
            if (pipe(fd_pipe) == -1)
                exit(0);
            data->exec[j + 1].fd_in = fd_pipe[0];
            data->exec[j].fd_out = fd_pipe[1];
        }
        else
            data->exec[j].fd_out = STDOUT_FILENO;
        if (j == 0)
            data->exec[j].fd_in = STDIN_FILENO;
        // printf("in = %d | out = %d\n", data->exec[j].fd_in, data->exec[j].fd_out);

        pid = fork();
        if (pid == -1)
            exit(EXIT_FAILURE);
         
        if (pid == 0) 
        {
            // printf("in = %d | out = %d\n", data->exec[j].fd_in, data->exec[j].fd_out);
            data->exec[j].cmd[0] = ft_path_dir(data->exec[j].cmd[0], ft_my_var(data, "PATH"), -1);
            //print/////////////////////////////////////////////
            for (int l = 0; data->exec[j].cmd[l]; l++)
                // printf("cmd[%d] = %s\n", l, data->exec[j].cmd[l]);
                /////////////////////////////////////////////////
            dup2(data->exec[j].fd_out, STDOUT_FILENO);
            dup2(data->exec[j].fd_in, STDIN_FILENO);
            if (data->exec[j].fd_out != STDOUT_FILENO)
                close(data->exec[j].fd_out);
            if (data->exec[j].fd_in != STDIN_FILENO)
                close(data->exec[j].fd_in); 
            
            execve(data->exec[j].cmd[0], data->exec[j].cmd, data->env);
            perror("execve a échoué ft_pipex i == 0\n");
            exit(EXIT_FAILURE);
        }
        else
        {
            if (data->exec[j].fd_in != STDIN_FILENO)
                close(data->exec[j].fd_in);
            if (data->exec[j].fd_out != STDOUT_FILENO)
                close(data->exec[j].fd_out);
            wait(NULL);
        }
        j++;
    }
    print_debug(data);
}


void	run_exec(t_data *data)
{

	ft_pipe(data);
}
