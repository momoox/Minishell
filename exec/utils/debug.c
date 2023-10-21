
#include "../header/util.h"

void    test_print(t_data *data)
{

    int i = 1;
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
