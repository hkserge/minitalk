CC			=	clang

CFLAGS		=	-Wall -Wextra -Werror -g

NAME		=	server

SRCS		=	srcs/server.c

HEADERS		=	-I includes

OBJECTS		=	${SRCS:.c=.o}

all:			$(NAME)

.c.o:
				@${CC} ${CFLAGS} ${HEADERS} -c $< -o ${<:.c=.o}

$(NAME) :		${OBJECTS}
				@${CC} ${CFLAGS} ${OBJECTS} ${HEADERS} -o ${NAME}
				@printf "\033[92mserver compiled\n\033[0m"

clean:

				@rm -rf ${OBJECTS}
				@printf "\033[92mclean done\n\033[0m"

fclean:			clean
				@rm -rf $(NAME)

re:				fclean all

.PHONY:			all clean fclean re bonus
