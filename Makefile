CC			=	clang

CFLAGS		=	-Wall -Wextra -Werror -g

SRCS_SERVER		=	srcs/server.c srcs/utils.c

SRCS_CLIENT		=	srcs/client.c srcs/utils.c

HEADERS		=	-I includes

OBJECTS_SERVER		=	${SRCS_SERVER:.c=.o}

OBJECTS_CLIENT		=	${SRCS_CLIENT:.c=.o}

all:			server client

.c.o:
				@${CC} ${CFLAGS} ${HEADERS} -c $< -o ${<:.c=.o}

server :		${OBJECTS_SERVER}
				@${CC} ${CFLAGS} ${OBJECTS_SERVER} ${HEADERS} -o server
				@printf "\033[92mserver compiled\n\033[0m"

client :		${OBJECTS_CLIENT}
				@${CC} ${CFLAGS} ${OBJECTS_CLIENT} ${HEADERS} -o client
				@printf "\033[92mclient compiled\n\033[0m"
clean:

				@rm -rf ${OBJECTS_SERVER}
				@rm -rf ${OBJECTS_CLIENT}
				@printf "\033[92mclean done\n\033[0m"

fclean:			clean
				@rm -rf server
				@rm -rf client

re:				fclean all

.PHONY:			all clean fclean re bonus
