SERVER	= server
SERVER_SRCS = server.c
#SERVER_BONUS = server_bonus
#SERVER_BONUS_SRCS = server_bonus.c

CLIENT = client
CLIENT_SRCS = client.c
#CLIENT_BONUS = client_bonus
#CLIENT_BONUS_SRCS = client_bonus.c

OBJS	= *.o 

CC=gcc

CFLAGS= -Wall -Wextra -Werror #-g -fsanitize=address

RM=rm -f

$(CLIENT): $(CLIENT_SRCS)
	$(CC) $(CFLAGS) $(CLIENT_SRCS) -o $(CLIENT)

$(SERVER): $(SERVER_SRCS)
	$(CC) $(CFLAGS) $(SERVER_SRCS) -o $(SERVER)

#all: $(SERVER) $(CLIENT)

clean:
	@$(RM) $(OBJS)

fclean: clean
	@${RM} $(CLIENT) $(SERVER) #$(SERVER_BONUS)

re: fclean all

.PHONY: all clean fclean re .c .o
