# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lcierra <lcierra@student.21-school.ru>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/31 19:32:37 by lcierra           #+#    #+#              #
#    Updated: 2021/04/04 21:41:04 by lcierra          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

CC = gcc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

MLX = mlx

LXFLAGS = -lmlx -framework OpenGL -framework AppKit

HEADER = head

SRCS =	cub.c \
	srcs/checker.c srcs/checker_utils.c \
	srcs/destroyer.c srcs/destroyer_parts.c \
	srcs/draw.c \
	srcs/exit.c \
	srcs/get_next_line.c srcs/get_next_line_utils.c \
	srcs/init.c srcs/init_parts.c \
	srcs/key.c \
	srcs/map_reader.c \
	srcs/parser_check_1.c srcs/parser_check_2.c srcs/parser_check_3.c srcs/parser_get.c srcs/parser_split.c  \
	srcs/player_reader.c \
	srcs/screenshot.c \
	srcs/sprite.c srcs/sprite_utils_count.c \
	srcs/texture.c srcs/texture_utils_count.c srcs/texture_utils_draw.c srcs/texture_utils_ray.c \
	srcs/utils_1.c srcs/utils_2.c srcs/utils_3.c srcs/utils_4.c

OBJS = 	${SRCS:.c=.o}

%.o: %.c
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

all:	makemlx ${NAME}

$(NAME):    	${OBJS}
		$(CC) -o $@ $^ -Lmlx $(LXFLAGS) -o $(NAME)

clean:
		make -C mlx clean 
		@${RM} ${OBJS}

cleancub:
		@${RM} ${OBJS}

fclean:	clean
		make -C mlx clean
		@${RM} ${NAME}

re:		fclean all

makemlx:
	make -C mlx
.PHONY: all clean fclean re cleancub