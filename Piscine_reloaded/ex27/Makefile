# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rrika <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/03 16:31:03 by rrika             #+#    #+#              #
#    Updated: 2019/04/03 16:31:24 by rrika            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_display_file

FLAG = -Wall -Wextra -Werror

FILES = ft_display_file.c ft_error.c

OBJ = ft_display_file.o ft_error.o

HEADER = ft.h

ALL: $(NAME)

$(NAME):
	@gcc $(FLAG) -o $(NAME) $(FILES) -I $(HEADER)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean ALL
