# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: selhanda <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/26 14:33:41 by selhanda          #+#    #+#              #
#    Updated: 2022/06/26 14:33:45 by selhanda         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=gcc
NAME=cub3d
SRC=main.c src/utils.c src/move.c map_parser/map_utils.c map_parser/parsing.c src/draw_utils.c src/calc_utils.c map_parser/get_map.c map_parser/get_next_line_utils.c map_parser/get_next_line.c map_parser/utils.c 
FLAGS=-Imlx -c $< -o $@
LIBNAME = Libft/libft.a
FFLAGS=-Wall -Wextra -Werror -lmlx -framework OpenGL -framework AppKit -Ofast
OBJ=$(SRC:.c=.o)

%.o: %.c
	$(CC) $(FLAGS)
$(NAME): $(OBJ)
	$(MAKE) -C Libft
	$(CC) $(OBJ) $(FFLAGS) $(LIBNAME) -o $(NAME)

clean:
	$(MAKE) clean -C Libft
	rm -rf $(OBJ)
fclean:clean
	rm -rf $(LIBNAME)
	rm -f $(NAME)
re:fclean $(NAME)
