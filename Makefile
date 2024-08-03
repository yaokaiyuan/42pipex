# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ykai-yua <ykai-yua@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/15 19:21:28 by ykai-yua          #+#    #+#              #
#    Updated: 2024/08/03 22:43:46 by ykai-yua         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

SRCS = pipex.c \
			utils.c
OBJS = $(SRCS:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror -Iincludes -g3

RM = rm -rf

all: ${NAME}
${NAME}: ${OBJS}
	${MAKE} -C ./libft
	${CC} ${CFLAGS} ${OBJS} ./libft/libft.a -o ${NAME}

clean: 
	${MAKE} -C ./libft fclean
	${RM} ${OBJS}

fclean: clean
	 ${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
