/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_pipe.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oliove <olivierliove@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 02:47:43 by oliove            #+#    #+#             */
/*   Updated: 2023/10/04 02:37:39 by oliove           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
on recois noeud par noeud :
	- data->exec->content
	- data->exec->token
	- data->env
les data que jai bessoin dans la struct
*/
#include "../header/util.h"

// static int	ft_pipex2(t_data *data, int *fd_stdin, int *fd_stdout)
// {
// 	int	cmd1;
// 	int	i;
// 	// int	fd[2];
// 	// (void)fd_stdin;
// 	// (void)fd_stdout;
    
// 	cmd1 = 1;
// 	i = 0;
//     printf("ft_pipex2 == data->fd_in[%d] | fd_stdin == [%d] | fd_stdout == [%d] | cmd == [%d]\n",data->exec->fd_in, *fd_stdin, *fd_stdout ,cmd1);
// 	if (data->exec->stdin_st && data->list->token == REDIR_IN)
// 		*fd_stdin = file_o(data->exec->cmd[0], 0);
// 	if (data->exec->fd_in == -1)
// 		cmd1 = 0;
// 	if(data->exec->stdout_st && data->list->token ==  REDIR_OUT)
// 		*fd_stdout = file_o(data->exec->cmd[0], 1);
// 	if (!cmd1)
// 	{
// 		i++;
// 		pipe(fd_stdin);
//         close(*fd_stdout);
// 		// data->exec->fd_in = fd[0];
// 		*fd_stdin = data->exec->fd_in;
// 	}
// 	return (i);
// }


//int ac, char **av, char **env)
// void	ft_pipex(t_data *data)
// {
// 	int	i;
// 	int	fd_stdin;
// 	int	fd_stdout;
// 	int fd_pipe[2];
//     char *path;
//     path = ft_path_dir(data->exec->cmd[0], ft_my_var(data, "PATH"), -1);
// 	pid_t pid;

// 	if (pipe(fd_pipe) == -1)
// 		exit(0);
// 	pid = fork();
// 	if (pid == -1)
// 		exit(0);
//     if (pid == 0)
//     {   
//         i = ft_pipex2(data,&fd_stdin,&fd_stdout);// &data->exec->fd_in, &data->exec->fd_out);
//         dup2(data->exec->fd_in, 0);
//         close(data->exec->fd_in);
//         while (i++ < count_pipe(data->list))
//             ft_pipe(data, data->exec->cmd[i],data->env);
//             // data->exec->cmd[0], data->env);
//         if (fd_stdout != -1)//data->exec->fd_out != -1)
//         {
//             dup2(fd_stdout,1);//data->exec->fd_out, 1);
//             close(fd_stdout);//data->exec->fd_out);
//             execve(path, &data->exec->cmd[0], data->env);
//             perror("ft_pipex error execve");
//             exit(EXIT_FAILURE);
//             // exece(data, &data->exec->cmd[0], data->env);
//         }
//         // else
//         // 	p_error_perm(data->exec->cmd[0]);
//     }
// }

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

void ft_pipex(t_data *data)
{
    // int i;
    int j;
    // int fd_stdin;
    // int fd_stdout;
    int fd_pipe[2];
    pid_t pid;
    // char *path;
    // char *args;
    // path = ft_path_dir(data->exec->cmd[0], ft_my_var(data, "PATH"), -1);
	// char *tmp;

    printf("exec : %d\n", data->nb_exec);
    for (int k = 0; k < data->nb_exec; k++)
        for (int l = 0; data->exec[k].cmd[l]; l++)
            printf("%d : cmd[%d] = %s\n", k, l, data->exec[k].cmd[l]);
   
    // while (data->exec->cmd[j] != NULL)
    // {
    // printf("ft_pipex : data->fd_in == [%d] | data->fd_out == [%d]\n", data->exec->fd_in, data->exec->fd_out);
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
        printf("in = %d | out = %d\n", data->exec[j].fd_in, data->exec[j].fd_out);

        pid = fork();
        if (pid == -1)
            exit(EXIT_FAILURE);
         
        // while (data->exec)
        // {
            if (pid == 0) 
            {
                printf("in = %d | out = %d\n", data->exec[j].fd_in, data->exec[j].fd_out);
                data->exec[j].cmd[0] = ft_path_dir(data->exec[j].cmd[0], ft_my_var(data, "PATH"), -1);
                for (int l = 0; data->exec[j].cmd[l]; l++)
                    printf("cmd[%d] = %s\n", l, data->exec[j].cmd[l]);
                // i = ft_pipex2(data, &data->exec[j].fd_in, &data->exec[j].fd_out);
                // printf("i == [%d]\n",i);
                // if (j == 0)
                // {
                dup2(data->exec[j].fd_out, STDOUT_FILENO);
                dup2(data->exec[j].fd_in, STDIN_FILENO);
                if (data->exec[j].fd_out != STDOUT_FILENO)
                    close(data->exec[j].fd_out);
                if (data->exec[j].fd_in != STDIN_FILENO)
                    close(data->exec[j].fd_in); 
                // exece(data, data->exec->cmd, data->env);
                execve(data->exec[j].cmd[0], data->exec[j].cmd, data->env);
                perror("execve a échoué ft_pipex i == 0\n");
                exit(EXIT_FAILURE);
                // }
                // else if(j < ft_lstsize(data->list) - 1) 
                // {
                //     printf("Loop\n");
                //     // close(data->exec->fd_in); 
                //     // close(data->exec->fd_out);

                //     ft_pipe(data, data->exec[j] data->env);
                // }
                // else 
                // {
                //     dup2(data->exec->fd_in, 0);
                //     close(data->exec->fd_out); 
                //     // exece(data, data->exec->cmd, data->env);
                //     execve(path, data->exec->cmd, data->env);
                //     // execve(data->exec->cmd[0], data->exec->cmd, data->env);
                //     perror("execve a échoué ft_pipex else");
                //     exit(EXIT_FAILURE);
                // }
            }
            else
            {
                if (data->exec[j].fd_in != STDIN_FILENO)
                    close(data->exec[j].fd_in);
                if (data->exec[j].fd_out != STDOUT_FILENO)
                    close(data->exec[j].fd_out);
                wait(NULL);
            }
            // data->exec = data->exec++;
            j++;
        }
        
     
    //     j++;
    // }
    
}

void    test_print(t_data *data)
{
    t_exec *tmp;

    int i = 1;
    tmp = data->exec;
    printf("[hello %p]\n",data->exec[i].stdin_st);
    if (data->exec && data->exec[i].stdin_st)
    {
        if (data->exec[i].cmd)
            printf("[%s]\n",data->exec->cmd[0]);
    }
    
        // printf("token_pipe == \n");
    // if (tmp[i].stdin_st->token == 2)
    //     printf("token_files == [%d]\n",tmp[i].stdin_st->token);
    // if (tmp[i].stdin_st->token == 3)
    //     printf("token_commande == [%d]\n",tmp[i].stdin_st->token);
    // if (tmp[i].stdin_st->token == 4)
    //     printf("token_redir_in == [%d]\n",tmp[i].stdin_st->token);
    // if (tmp[i].stdin_st->token == 5)
    //     printf("token_redir_append == [%d]\n",tmp[i].stdin_st->token);
    // if (tmp[i].stdin_st->token == 6)
    //     printf("token_out == [%d]\n",tmp[i].stdin_st->token);
    // if (tmp[i].stdin_st->token == 7)
    //     printf("token_here_doc == [%d]\n",tmp[i].stdin_st->token);

}

//int ac, char **av, char **env)
void	run_exec(t_data *data)
{
    // print_exec(data);
    // test_print(data);
	// if (ac < 5)
	// 	return (1);
	// ft_check_error_parser(ac, av);
	ft_pipex(data);//ac, av, env);
}
