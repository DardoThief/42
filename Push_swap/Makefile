# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rrika <rrika@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/31 16:57:22 by rrika             #+#    #+#              #
#    Updated: 2019/08/09 17:51:38 by rrika            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CHECK = checker

PUSH = push_swap

SRC_CHECK = checker_folder/checker.c

SRC_PUSH = push_swap_folder/push_swap.c 

SRC = push_swap_folder/sorting_hat.c \
			push_swap_folder/parse_args.c \
			push_swap_folder/lst.c \
			push_swap_folder/get_flags.c \
			push_swap_folder/for_commands.c \
			push_swap_folder/for_commands_two.c \
			push_swap_folder/for_commands_three.c \
			commands/first_commands.c \
			commands/second_commands.c \
			commands/third_commands.c 

INC = push_swap.h

LIB = libft/libft.a

all: $(PUSH) $(CHECK)

$(PUSH): $(SRC_PUSH)
		@$(MAKE) -C ./libft
		gcc -ggdb -Wall -Wextra -Werror $(SRC_PUSH) $(SRC) $(LIB) -I $(INC) -o $(PUSH)

$(CHECK): $(SRC_CHECK)
		@$(MAKE) -C ./libft
		gcc -Wall -Wextra -Werror $(SRC_CHECK) $(SRC) $(LIB) -I $(INC) -o $(CHECK)

clean:
		@$(MAKE) -C ./libft clean

fclean: clean
		@$(MAKE) -C ./libft fclean
		rm -f $(PUSH) $(CHECK)

re: fclean all  