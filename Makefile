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
SRC=main.c src/utils.c src/move.c src/file_for_norm.c map_parser/parsing_utils.c src/init_func.c src/general_utils.c map_parser/map_utils.c map_parser/parsing.c src/draw_utils.c src/calc_utils.c map_parser/get_map.c map_parser/get_next_line_utils.c map_parser/get_next_line.c map_parser/utils.c map_parser/norm.c map_parser/checkmap.c
LIBNAME = Libft/libft.a
OBJ=$(SRC:.c=.o)

%.o: %.c
	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@

$(NAME):$(OBJ)
	$(MAKE) -C Libft
	$(CC) $(OBJ) -lmlx -framework OpenGL -framework AppKit $(LIBNAME) -o $(NAME)

all: $(NAME)

clean:
	$(MAKE) clean -C Libft
	rm -rf $(OBJ)

fclean:clean
	rm -rf $(LIBNAME)
	rm -f $(NAME)

re:fclean all
