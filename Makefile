# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: momox <momox@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/28 20:23:57 by momox             #+#    #+#              #
#    Updated: 2023/09/06 16:00:28 by momox            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

SRCS = main.c init_struct.c print_tab.c \
		libft/ft_strchr.c \
		libft/ft_strdup.c \
		libft/ft_strncmp.c \
		parser/parser.c \
		parser/split_commands.c \
		parser/whitespace.c \
		parser/ft_split_whitespaces.c \
		parser/ft_split_operators.c \
		lists/print_list.c \
		lists/list_utils.c \
		lists/list_utils_2.c \

OBJECTS = $(SRCS:.c=.o)

GCC = gcc -Wall -Werror -Wextra -lreadline -g3 -fsanitize=address

all : $(NAME)

$(NAME): $(OBJECTS)
		$(GCC) $(SRCS) -o $(NAME)

clean:
		rm -f $(OBJECTS)

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re test