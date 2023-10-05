/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oliove <olivierliove@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 15:40:29 by mgeisler          #+#    #+#             */
/*   Updated: 2023/10/03 00:07:47 by oliove           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void print_debug(t_data *data)
{
	for(int i = 0; i < data->nb_exec; i++)
	{
		printf("---------- EXEC[%d] -----------\n",i);
		printf("	fd_in = %d\n",data->exec[i].fd_in);
		printf("	fd_out = %d\n",data->exec[i].fd_out);
		for (int i2 = 0; data->exec[i].cmd[i2]; i2++)
			printf("Cmd[%d] = '%s'",i2,data->exec[i].cmd[i2]);
		printf("STDIN _ IN\n");
		print_list(data->exec[i].stdin_st);
		printf("STDIN _ OUT\n");
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
		// print_debug(data);
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
