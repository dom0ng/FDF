# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: julin <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/23 08:06:35 by julin             #+#    #+#              #
#    Updated: 2018/04/29 03:27:29 by julin            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	fdf
SRC =		mlx_atoi_at.c \
			mlx_grid.c \
			mlx_line.c \
			mlx_set.c \
			mlx_set_1.c \
			mlx_set_2.c \
			mlx_interface_1.c \
			mlx_interface_2.c \
			mlx_interface_3.c \
			mlx_interface_4.c \
			fdf.c \
			mlx_put_pixel_img.c

INC =		srcs/minilibx_macos/libmlx.a \
			srcs/libft/libft.a
SRCS =		$(addprefix srcs/,$(SRC))
OBJ =		$(SRC:.c=.o)
CFLAGS =	-Wall -Wextra -Werror
DFLAGS =	-lmlx -framework OpenGL -framework AppKit
CC =		@gcc


all: $(NAME)

$(NAME): $(OBJ) $(INC)
	$(CC) -o $(NAME) $(DFLAGS) $(OBJ) -I $(INC)

$(OBJ) : $(SRCS)
	$(CC) -c $(CFLAGS) $(SRCS) -I includes/

$(INC) :
	make -C srcs/libft/
	make -C srcs/minilibx_macos/

clean:
	@rm -f $(OBJ)
	make -C srcs/libft/ clean
	make -C srcs/minilibx_macos/ clean

fclean: clean
	@rm -f $(NAME)
	make -C srcs/libft/ fclean
	make -C srcs/minilibx_macos/ clean


re: fclean all
