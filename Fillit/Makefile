# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbernard <mbernard@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/07 14:29:19 by mbernard          #+#    #+#              #
#    Updated: 2019/05/07 15:22:06 by mbernard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
SRC = board.c \
	fillit.c \
	funcs.c \
	listfunc.c \
	main.c \
	reading.c \
	solving.c \
	validation.c \
	addone.c \
	addtwo.c \

OBJ  = ${SRC:.c=.o}

FLAGS = -Wall -Werror -Wextra

.PHONY: all
all: ${NAME}

%.o:%.c
	gcc $(FLAGS) -o $@ -c $<

$(NAME): $(OBJ)
	gcc -o $(NAME) $(OBJ)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all