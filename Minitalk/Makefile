# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbarredo <jbarredo@student.42urduli>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/05 12:56:40 by jbarredo          #+#    #+#              #
#    Updated: 2022/03/05 20:20:35 by jbarredo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER	= server
SERVER_SRCS = server.c\
			  utils.c
#SERVER_BONUS = server_bonus
#SERVER_BONUS_SRCS = server_bonus.c

CLIENT = client
CLIENT_SRCS = client.c\
			  utils.c
#CLIENT_BONUS = client_bonus
#CLIENT_BONUS_SRCS = client_bonus.c

INCLUDES = Minitalk.h

OBJS	= client.o\
		 utils.o

OBJS_SERV = server.o\
			utils.o

CC=gcc

CFLAGS= -Wall -Wextra -Werror #-g -fsanitize=address

RM=rm -f

$(CLIENT):
	@${CC} ${CFLAGS} -c ${CLIENT_SRCS} -I${INCLUDES}
	@${CC} ${CFLAGS} -o ${CLIENT} ${OBJS}	

$(SERVER):
	@${CC} ${CFLAGS} -c ${SERVER_SRCS} -I${INCLUDES}
	@${CC} ${CFLAGS} -o ${SERVER} ${OBJS_SERV}

all: $(SERVER) $(CLIENT)

clean:
	@$(RM) $(OBJS)

fclean: clean
	@${RM} $(CLIENT) $(SERVER) #$(SERVER_BONUS)

re: fclean all

.PHONY: all clean fclean re .c .o
