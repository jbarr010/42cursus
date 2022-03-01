# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbarredo <jbarredo@student.42urduli>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/09 20:19:46 by jbarredo          #+#    #+#              #
#    Updated: 2022/02/28 16:05:10 by jbarredo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= push_swap

SRCS	=  array_to_list.c\
		   checker.c\
		   create_stack.c\
		   main.c\
		   median.c\
		   moves.c\
		   sort_hundred.c\
		   sort_small.c\
		   sort_500.c\
		   q500.c\
		   utils.c\
		   sort_rest.c\
		   split.c\
		   median_aux.c\
		   moves_b.c\
		   sort_five.c\
		   sort_utils.c\
		   sort_500_2.c\
		   q500_2.c

OBJS	= *.o 

INCLUDES = push_swap.h

CC=gcc

CFLAGS= -Wall -Wextra -Werror -g -fsanitize=address

RM=rm -f

$(NAME):
		@${CC} ${CFLAGS} -c ${SRCS} -I${INCLUDES}
		@${CC} ${CFLAGS} -o ${NAME} ${OBJS}
all: $(NAME)

clean:
	@$(RM) $(OBJS)

fclean: clean
	@${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re .c .o
