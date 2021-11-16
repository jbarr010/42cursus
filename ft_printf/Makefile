# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbarredo <jbarredo@student.42urduli>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/08 18:59:19 by jbarredo          #+#    #+#              #
#    Updated: 2021/11/15 19:50:47 by jbarredo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a

SRCS	= $(wildcard ./*.c)

OBJS	= $(patsubst ./%.c, ./%.o, $(SRCS))

LIBFT=libft

CC=gcc

CFLAGS=-Wall -Wextra -Werror

RM=rm -f

$(NAME): $(OBJS)
	@make -C $(LIBFT)
	@cp libft/libft.a ./$(NAME)
	@ar -rcs $(NAME) $(OBJS)
	@mkdir objs
	@mv $(OBJS) ./objs
	@rm -f $(OBJS)
	@rm -Rf objs

all: $(NAME)

clean:
	@$(RM) $(OBJS)
	@make clean -C $(LIBFT)

fclean: clean
	@${RM} libftprintf.a
	@make fclean -C $(LIBFT)

re: fclean all

.PHONY: all clean fclean re .c .o
