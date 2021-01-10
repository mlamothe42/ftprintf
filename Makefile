SRCS		=	./srcs/ft_printf.c ./srcs/ft_mem_handle.c ./srcs/ft_inits.c ./srcs/ft_checks.c ./srcs/ft_handle.c ./srcs/ft_handle_conv.c ./srcs/ft_handle_conv2.c ./srcs/ft_util_conv.c

HDRS		= ./includes

OBJS		= ${SRCS:.c=.o}

NAME		= libftprintf.a

CC			= gcc

CFLAG		=  -Wall -Wextra -Werror

OPTS		= ${ADDLIBFT} -c -I ${HDRS}

RM			= rm -f

ADDLIBFT	= -L./libft -lft

all:		${NAME}

mklibft:
		$(MAKE) -C libft

.c.o:
		${CC} ${OPTS} ${CFLAG} $< -o ${<:.c=.o}

${NAME}:	mklibft ${OBJS}
			ar rc ${NAME} ${OBJS} ./libft/libft.a
			ranlib ${NAME}

test:		mklibft ${OBJS}
		gcc ${SRCS} -L./libft -lft -I ${HDRS}  -fsanitize=address

bonus:		${NAME} ${OBJS_BONUS}
			ar rc ${NAME} ${OBJS_BONUS}
			ranlib ${NAME}

clean:		
			$(MAKE) -C libft clean
			${RM} ${OBJS} ${OBJS_BONUS}

fclean:		clean
			${RM} ./libft/libft.a
			${RM} ${NAME}
			
re:			fclean all

.PHONY:		all clean fclean re bonus
