

################################################################################
#                                     CONFIG                                   #
################################################################################

NAME		:=	pipex
CC			:=	gcc
FLAGS		:=	-Wall -Wextra -Werror

ifeq ($(DEBUG), 1)
	FLAGS	+=	-g3 -fsanitize=address
endif
################################################################################
#                                 PROGRAM'S SRCS                               #
################################################################################



SRCS		:=	src/main.c \
				src/path_cmd.c \
				src/processes.c \
				utils/utils_str.c \
				utils/ft_split.c \
				lib/get_next_line/get_next_line.c \
				lib/get_next_line/get_next_line_utils.c \
				utils/ft_error.c \
				utils/ft_strcmp.c \

BONUS_SRCS	:=	src/main_bonus.c \
				src/path_cmd.c \
				src/processes.c \
				utils/utils_str.c \
				utils/ft_split.c \
				src/ft_here_doc.c \
				lib/get_next_line/get_next_line.c \
				lib/get_next_line/get_next_line_utils.c \
				utils/ft_error.c \
				utils/ft_strcmp.c \



OBJS		:=	$(SRCS:.c=.o)
OBJS_BONUS	:=	$(BONUS_SRCS:.c=.o)


.c.o:
	@ $(CC) $(FLAGS) -c $< -o $(<:.c=.o)

################################################################################
#                                  Makefile  objs                              #
################################################################################


CLR_RMV		:=	\033[0m
RED			:=	\033[1;31m
GREEN		:=	\033[1;32m
YELLOW		:=	\033[1;33m
BLUE		:=	\033[1;34m
CYAN 		:=	\033[1;36m
RM			:=	rm -f

all:			$(NAME)

$(NAME):		$(OBJS)
				@ echo "$(GREEN)Compilation $(CLR_RMV)of $(YELLOW)$(NAME) $(CLR_RMV)..."
				@ $(CC) $(FLAGS) -o $(NAME) $(OBJS)
				@ echo "$(GREEN)$(NAME) created[0m ✔️"

bonus:			$(OBJS_BONUS) 
				@ echo "$(GREEN)Compilation $(CLR_RMV)of $(YELLOW)$(NAME) $(CLR_RMV)..."
				@ $(CC) $(FLAGS) -o $(NAME) $(OBJS_BONUS)
				@ echo "$(GREEN)$(NAME) created[0m ✔️"

clean:
				@ $(RM) $(OBJS) $(OBJS_BONUS)
				@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)objs ✔️"

fclean:			clean
				@ $(RM) $(NAME)
				@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)binary ✔️"

re:				fclean all

.PHONY:			all clean fclean re bonus