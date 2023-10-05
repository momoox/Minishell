/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oliove <olivierliove@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 15:40:29 by mgeisler          #+#    #+#             */
/*   Updated: 2023/10/05 18:30:14 by oliove           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
/*
	Bleu \033[0;34m
	Noir \033[0;30m
	Rouge \033[0;31m
	Vert \033[0;32m
	Jaune \033[0;33m
	Violet \033[0;35m
*/

void print_debug(t_data *data)
{
	for(int i = 0; i < data->nb_exec; i++)
	{
		printf("\033[0;34m---------- EXEC[%d] -----------\033[0m\n",i);
		printf("	fd_in = \033[0;31m[%d]\033[0m\n",data->exec[i].fd_in);
		printf("	fd_out = \033[0;31m[%d]\033[0m\n",data->exec[i].fd_out);
		if(data->exec[i].cmd)
		for (int i2 = 0; data->exec[i].cmd[i2]; i2++)
			printf("Cmd[%d] = '%s'",i2,data->exec[i].cmd[i2]);
		printf("\033[0;34mSTDIN _ IN\033[0m\n");
		print_list(data->exec[i].stdin_st);
		printf("\033[0;34mSTDIN _ OUT\033[0m\n");
		print_list(data->exec[i].stdout_st);
	}
}

void	reader(t_data *data)
{
	while (1)
	{
		rl_catch_signals = 0;
		signal(SIGINT, sig_handler);
		signal(SIGQUIT, sig_handler);
		reinit(data);
		data->input = readline("minishell> ");
		if (!data->input)
			break ;
		if (data->input[0] == 0)
		{
			free(data->input);
			continue ;
		}
		add_history(data->input);
		parser(data);
		print_debug(data);
		// run_exec(data);
		free(data->input);
	}
}

int	main(int argc, char **argv, char **env)
{
	t_data	data;

	(void)argc;
	(void)argv;
	init_data(&data);
	tab_env(&data, env);
	reader(&data);
}
