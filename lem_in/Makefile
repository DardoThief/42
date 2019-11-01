# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smanhack <smanhack@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/27 12:36:50 by noobythetur       #+#    #+#              #
#    Updated: 2019/10/25 18:38:02 by smanhack         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= lem-in

SRC_NOVISU = solution.c lem_in.c dijkstra.c fill_ways.c suurballe.c way_out.c processing.c rooms.c useful_func.c reading.c main_func.c dijkstra_init.c create_links2.c create_links.c checking.c add_rooms.c free.c

SRC		= solution.c lem_in.c dijkstra.c fill_ways.c suurballe.c way_out.c processing.c sdl.c sdl1.c sdl2.c sdl3.c rooms.c useful_func.c reading.c main_func.c dijkstra_init.c create_links2.c create_links.c checking.c add_rooms.c free.c

FLAGS	= -march=native -Ofast

OBJ		= $(SRC:.c=.o)

LIB		= ./ft_printf_git/

all: $(NAME)

%.o: %.c
	@gcc $(FLAGS) -c $< -o $@ -I ~/.brew/include/SDL2/

$(NAME): $(OBJ)
	@make -C $(LIB)
	@gcc $(FLAGS) -o $(NAME) $(OBJ) -I ~/.brew/include/SDL2/ -L ~/.brew/lib -lSDL2 -lSDL2_image -lSDL2_gfx -lSDL2_mixer -L$(LIB) -lftprintf

novisu:
	@gcc -g $(FLAGS) -o $(NAME) $(SRC_NOVISU) -L$(LIB) -lftprintf

test:
	@gcc -g $(FLAGS) -o $(NAME) $(SRC) -I ~/.brew/include/SDL2/ -L ~/.brew/lib -lSDL2 -lSDL2_image -lSDL2_gfx -lSDL2_mixer -L$(LIB) -lftprintf

try:
	@gcc $(FLAGS) -o $(NAME) $(SRC) -I ~/.brew/include/SDL2/ -L ~/.brew/lib -lSDL2 -lSDL2_image -lSDL2_gfx -lSDL2_mixer -L$(LIB) -lftprintf
	
clean:
	@make -C $(LIB) clean
	@rm -rf $(OBJ)
	
fclean: clean
	@make -C $(LIB) fclean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
