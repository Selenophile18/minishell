SRCS	= $(wildcard ./builtins/*.c) $(wildcard ./execution/*.c) $(wildcard ./parsing/*.c)

CC		= cc

CFLAGS	= -Wall -Wextra -Werror

NAME	= minishell

MK_FILE	= Makefile

# LIBFT	= ./libft/libft.a

all		: $(NAME)

$(NAME) : $(SRCS) $(MK_FILE)
		$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

clean	: rm -rf $(NAME)

fclean	: rm -rf $(NAME)

re		: fclean re
