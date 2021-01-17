SRCS		= ./srcs/ft_printf.c ./srcs/ft_mem_handle.c ./srcs/ft_inits.c ./srcs/ft_checks.c ./srcs/ft_handle.c ./srcs/ft_handle_conv.c ./srcs/ft_handle_conv2.c ./srcs/ft_util_conv.c

HDRS		= ./includes

OBJS		= ${SRCS:.c=.o}

NAME		= libftprintf.a

CFLAG		= -Wall -Wextra -Werror

OPTS		= ${ADDLIBFT} -c -I ${HDRS}

ADDLIBFT	= -L./libft -lft

all:		${NAME}

mklibft:
		make -C libft

.c.o:
		gcc ${OPTS} ${CFLAG} $< -o ${<:.c=.o}

${NAME}:	mklibft ${OBJS}
			cp ./libft/libft.a ${NAME}
			ar rcs ${NAME} ${OBJS}

test:		mklibft ${OBJS}
		gcc ${SRCS} -L./libft -lft -I ${HDRS} -fsanitize=address

bonus:		${NAME} ${OBJS_BONUS}
			ar rc ${NAME} ${OBJS_BONUS}
			ranlib ${NAME}

clean:		
			make -C libft clean
			rm -f ${OBJS} ${OBJS_BONUS}

fclean:		clean
			make -C libft fclean
			rm -f ${NAME}

re:			fclean all

.PHONY:		all clean fclean re bonus
