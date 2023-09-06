/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momox <momox@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 15:40:29 by mgeisler          #+#    #+#             */
/*   Updated: 2023/09/04 13:52:06 by momox            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// void	sig_handler(int signo)
// {
// 	if (signo == SIGINT)
// 	{
// 		printf("\n");
// 		rl_on_new_line();
// 		rl_replace_line("", 0);
// 		rl_redisplay();
// 	}
// }

		//signal(SIGINT, sig_handler);
void	reader(t_data *data)
{
	while (1)
	{
		data->input = readline("minishell> ");
		add_history(data->input);
		parser(data);
		free(data->input);
	}
}

int	main(void)
{
	t_data	data;

	init_data(&data);
	reader(&data);
}

//faire fonctionner le split