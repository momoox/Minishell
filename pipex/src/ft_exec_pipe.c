/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_pipe.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oliove <olivierliove@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 02:47:43 by oliove            #+#    #+#             */
/*   Updated: 2023/10/03 04:11:10 by oliove           ###   ########.fr       */
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

static int	ft_pipex2(t_data *data, int *fd_stdin, int *fd_stdout)
{
	int	cmd1;
	int	i;
	int	fd[2];
	// (void)fd_stdin;
	// (void)fd_stdout;
    
	cmd1 = 1;
	i = 2;
	if (data->exec->stdin_st && data->list->token == REDIR_IN)
		*fd_stdin = file_o(data->exec->cmd[0], 0);
	if (data->exec->fd_in == -1)
		cmd1 = 0;
	if(data->exec->stdout_st && data->list->token ==  REDIR_OUT)
		*fd_stdout = file_o(data->exec->cmd[0], 1);
	if (!cmd1)
	{
		i++;
		pipe(data->exec->fd_pipe);
        close(data->exec->fd_pipe[1]);
		// data->exec->fd_in = fd[0];
		*fd_stdin = fd[0];
	}
	return (i);
}


//int ac, char **av, char **env)
// void	ft_pipex(t_data *data)
// {
// 	int	i;
// 	int	fd_stdin;
// 	int	fd_stdout;
// 	int fd_pipe[2];

// 	pid_t pid;

// 	if (pipe(fd_pipe) == -1)
// 		exit(0);
// 	pid = fork();
// 	if (pid == -1)
// 		exit(0);

// 	i = ft_pipex2(data,&fd_stdin,&fd_stdout);// &data->exec->fd_in, &data->exec->fd_out);
// 	dup2(data->exec->fd_in, 0);
// 	close(data->exec->fd_in);
// 	while (i++ < count_pipe(data->list))
// 		ft_pipe(data);
// 		// data->exec->cmd[0], data->env);
// 	if (fd_stdout != -1);//data->exec->fd_out != -1)
// 	{
// 		dup2(fd_stdout,1);//data->exec->fd_out, 1);
// 		close(fd_stdout);//data->exec->fd_out);
// 		exece(data, data->exec->cmd[0], data->env);
// 	}
// 	else
// 		p_error_perm(data->exec->cmd[0]);
// }
void ft_pipex(t_data *data)
{
    int i;
    int j;
    // int fd_stdin;
    // int fd_stdout;
    // int fd_pipe[2];
    pid_t pid;
	// char *tmp;
    j = 0;
    // while (data->exec->cmd[j] != NULL)
    // {
     
        if (pipe(data->exec->fd_pipe) == -1)
            exit(0);

        pid = fork();
        if (pid == -1)
            exit(0);
    
        if (pid == 0) 
        {
            i = ft_pipex2(data, &data->exec->fd_in, &data->exec->fd_out);
            // tmp = data->exec->cmd[j];
            // printf("ft_pipex; tmp == [%s]\n",tmp);
            // data->exec->cmd[j] = ft_my_path(data, tmp, data->env);
            // printf("data->exec->cmd[j] == [%s]\n",data->exec->cmd[j]);
            if (i == 0)
            {
                dup2(data->exec->fd_pipe[1], 1);
                close(data->exec->fd_pipe[0]); 
                
                exece(data, data->exec->cmd, data->env);
                // execve(data->exec->cmd[0], data->exec->cmd, data->env);
                // perror("execve a échoué");
                // exit(EXIT_FAILURE);
            }
            else if (i < count_pipe(data->list)) 
            {
                close(data->exec->fd_pipe[0]); 
                close(data->exec->fd_pipe[1]);

                ft_pipe(data,data->exec->cmd[j], data->env);
            }
            else 
            {
                dup2(data->exec->fd_pipe[0], 0);
                close(data->exec->fd_pipe[1]); 
                exece(data,data->exec->cmd, data->env);
                // execve(data->exec->cmd[0], data->exec->cmd, data->env);
                // execve(data->exec->cmd[0], data->exec->cmd, data->env);
                // perror("execve a échoué");
                // exit(EXIT_FAILURE);
            }
        }
        else
        {
            close(data->exec->fd_pipe[0]);
            close(data->exec->fd_pipe[1]);
            wait(NULL);
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
