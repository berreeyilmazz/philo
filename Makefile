SRCS	= create.c ft_av.c main.c timing.c action.c repeat_dead.c destroy.c
OBJ		= $(SRCS:.c=.o)
NAME	= philo
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror -fsanitize=thread -g

all 	: $(NAME)

$(NAME)	: $(OBJ)
		$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean $(NAME)

.PHONY: all clean fclean re