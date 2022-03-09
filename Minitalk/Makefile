# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbarredo <jbarredo@student.42urduli>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/05 12:56:40 by jbarredo          #+#    #+#              #
#    Updated: 2022/03/09 15:24:55 by jbarredo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_SERVER	= server
SERVER_SRCS = server.c\
			  utils.c

SERVER_BONUS = server_bonus
SERVER_BONUS_SRCS = server_bonus.c\
					utils.c

NAME = client
CLIENT_SRCS = client.c\
			  utils.c

NAME_BONUS = client_bonus
CLIENT_BONUS_SRCS = client_bonus.c\
					utils.c

INCLUDES = Minitalk.h

OBJS	= client.o\
		 utils.o

OBJS_SERV = server.o\
			utils.o

OBJS_BONUS = client_bonus.o\
			 utils.o

OBJS_SERV_BONUS = server_bonus.o\
				  utils.o

CC=gcc

CFLAGS= -Wall -Wextra -Werror #-g -fsanitize=address

RM=rm -f

$(NAME):
	@${CC} ${CFLAGS} -c ${CLIENT_SRCS} -I${INCLUDES}
	@${CC} ${CFLAGS} -o ${NAME} ${OBJS}
	@${CC} ${CFLAGS} -c ${SERVER_SRCS} -I${INCLUDES}
	@${CC} ${CFLAGS} -o ${NAME_SERVER} ${OBJS_SERV}

bonus: $(NAME_BONUS)

$(NAME_BONUS):
	@${CC} ${CFLAGS} -c ${CLIENT_BONUS_SRCS} -I${INCLUDES}
	@${CC} ${CFLAGS} -o ${NAME_BONUS} ${OBJS_BONUS}
	@${CC} ${CFLAGS} -c ${SERVER_BONUS_SRCS} -I${INCLUDES}
	@${CC} ${CFLAGS} -o ${SERVER_BONUS} ${OBJS_SERV_BONUS}

all: $(NAME) $(NAME_BONUS)

clean:
	@$(RM) $(OBJS) $(OBJS_SERV) $(OBJS_BONUS) $(OBJS_SERV_BONUS)

fclean: clean
	@${RM} $(NAME) $(NAME_SERVER) $(NAME_BONUS) $(SERVER_BONUS) $(SERVER_BONUS) $(OBJS_BONUS) $(OBJS_SERV_BONUS)

re: fclean all

.PHONY: all clean fclean re .c .o
