# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oliove <olivierliove@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/28 20:23:57 by momox             #+#    #+#              #
#    Updated: 2023/09/29 22:29:46 by oliove           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = minishell

SRCS = main.c init_struct.c print_tab.c print_token.c\
		print_list.c \
		libft/ft_strchr.c \
		libft/ft_strdup.c \
		libft/ft_strncmp.c \
		libft/ft_strjoin.c \
		libft/ft_substr.c \
		libft/tab_env.c \
		libft/env_check.c \
		libft/env_replace.c \
		libft/ft_putstr.c \
		libft/ft_putendl.c \
		libft/ft_split.c \
		libft/ft_tab_addback.c \
		parser/parser.c \
		parser/split_commands.c \
		parser/whitespace.c \
		parser/ft_split_whitespaces.c \
		parser/ft_split_operators.c \
		parser/regroup_command.c \
		parser/tab_exec.c \
		parser/file_inout.c \
		parser/tokenize.c \
		parser/cmd_tab.c \
		lists/list_utils.c \
		lists/list_utils_2.c \
		pipex/src/ft_exec_pipe.c \
		pipex/src/processes.c \
		pipex/src/path_cmd.c \
		pipex/utils/ft_error.c \
		pipex/utils/utils_str.c \
		pipex/utils/ft_strcmp.c \
		# pipe.c \
		# test.c \

OBJECTS = $(SRCS:.c=.o)

INCLUDE = -I /opt/homebrew/Cellar/readline/8.2.1/include/
LIB = -lreadline -L /opt/homebrew/Cellar/readline/8.2.1/lib

ifeq (${42},1)
	LIB = -lreadline -L /Users/$$USER/.brew/opt/readline/lib
	INCLUDE = -I /Users/$$USER/.brew/opt/readline/include
endif


CC = gcc
CFLAGS = -Wall -Werror -Wextra -g3 -fsanitize=address 

ifeq ($(DEBUG), 1)
	CFLAGS	+=	-g3 -fsanitize=address
endif

.c.o:
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $(<:.c=.o)

all : $(NAME)

$(NAME): $(OBJECTS)
	@$(CC) $(CFLAGS) $(LIB) $(INCLUDE) $(SRCS) -o $(NAME)
 
clean:
	@rm -f $(OBJECTS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re test