SRCS	= $(wildcard *.c)

CC		= cc

CFLAGS	= -Wall -Wextra -Werror -g -fsanitize=address

NAME	= minishell

MK_FILE	= Makefile

LIBFT	= ./libft/libft.a

all		: $(NAME)

$(NAME) : $(SRCS) $(MK_FILE)
		make -C libft
		$(CC) $(CFLAGS) $(SRCS) $(LIBFT) -o $(NAME)

clean	: make clean -C libft

fclean	: rm -rf $(NAME)

re		: fclean re
