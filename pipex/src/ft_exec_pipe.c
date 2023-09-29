/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_pipe.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oliove <olivierliove@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 02:47:43 by oliove            #+#    #+#             */
/*   Updated: 2023/09/29 22:18:06 by oliove           ###   ########.fr       */
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
	
	
	cmd1 = 1;
	i = 2;
	if (data->list->token == REDIR_IN)
		 *fd_stdin = file_o(data->exec->cmd[0], 0);
	if (*fd_stdin == -1)
		cmd1 = 0;
	if(data->list->token ==  REDIR_OUT)
		*fd_stdout = file_o(data->exec->cmd[0], 1);
	if (!cmd1)
	{
		i++;
		pipe(fd);
		close(fd[1]);
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
    int fd_stdin;
    int fd_stdout;
    int fd_pipe[2];
    pid_t pid;
	char *tmp;

    if (pipe(fd_pipe) == -1)
        exit(0);

    pid = fork();
    if (pid == -1)
        exit(0);

    if (pid == 0) 
    {
        i = ft_pipex2(data, &fd_stdin, &fd_stdout);
		tmp = data->exec->cmd[0];
		data->exec->cmd[0] = ft_my_path(data, tmp, data->env);
        if (i == 0)
        {
            dup2(fd_pipe[1], 1);
            close(fd_pipe[0]); 
			
			// exece(data,*data->exec->cmd, data->env);
            execve(data->exec->cmd[0], data->exec->cmd, data->env);
            perror("execve a échoué");
            exit(EXIT_FAILURE);
        }
        else if (i < count_pipe(data->list)) 
        {
            close(fd_pipe[0]); 
            close(fd_pipe[1]);

            ft_pipe(data);
        }
        else 
        {
            dup2(fd_pipe[0], 0);
            close(fd_pipe[1]); 
			// exece(data,*data->exec->cmd, data->env);
            execve(data->exec->cmd[0], data->exec->cmd, data->env);
            // execve(data->exec->cmd[0], data->exec->cmd, data->env);
            perror("execve a échoué");
            exit(EXIT_FAILURE);
        }
    }
    else
    {
        close(fd_pipe[0]);
        close(fd_pipe[1]);

        wait(NULL);
    }
}

//int ac, char **av, char **env)
void	run_exec(t_data *data)
{
    print_exec(data);
	// if (ac < 5)
	// 	return (1);
	// ft_check_error_parser(ac, av);
	ft_pipex(data);//ac, av, env);
}
