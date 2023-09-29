/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oliove <olivierliove@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 02:47:43 by oliove            #+#    #+#             */
/*   Updated: 2023/09/26 23:07:19 by oliove           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/util.h"

/*
on recois noeud par noeud :
	- data->exec->content
	- data->exec->token
	- data->env
les data que jai bessoin dans la struct
*/

// static void	ft_pipex_here_doc(t_data *data)//int ac, char **av, char **env)
// {
// 	int	i;
// 	int	fd_stdout;

// 	// fd_stdout = file_o(av[ac - 1], 2);
// 	ft_here_doc(av);
// 	while (i < ac - 2)
// 		ft_pipe(av[i++], env);
// 	if (fd_stdout != -1)
// 	{
// 		dup2(fd_stdout, 1);
// 		close(fd_stdout);
// 		exece(av[ac - 2], env);
// 	}
// 	else
// 		p_error_perm(av[ac - 1]);
// }

static int	ft_pipex2(int *fd_stdin, int *fd_stdout, int ac, char **av)
{
	int	cmd1;
	int	i;
	int	fd[2];

	cmd1 = 1;
	i = 2;
	*fd_stdin = file_o(av[1], 0);
	if (*fd_stdin == -1)
		cmd1 = 0;
	*fd_stdout = file_o(av[ac - 1], 1);
	if (!cmd1)
	{
		i++;
		pipe(fd);
		close(fd[1]);
		*fd_stdin = fd[0];
	}
	return (i);
}

static void	ft_pipex(int ac, char **av, char **env)
{
	int	i;
	int	fd_stdin;
	int	fd_stdout;

	i = ft_pipex2(&fd_stdin, &fd_stdout, ac, av);
	dup2(fd_stdin, 0);
	close(fd_stdin);
	while (i < ac - 2)
		ft_pipe(av[i++], env);
	if (fd_stdout != -1)
	{
		dup2(fd_stdout, 1);
		close(fd_stdout);
		exece(av[ac - 2], env);
	}
	else
		p_error_perm(av[ac - 1]);
}

int	run_exec(t_data *data, int ac, char **av, char **env)
{
	// if (ac < 5)
	// 	return (1);
	// ft_check_error_parser(ac, av);
	if (data->exec->__stdinp->token == REDIR_HERE_DOC )
		ft_pipex_here_doc(ac, av, env);
	else
		ft_pipex(ac, av, env);
	
}
