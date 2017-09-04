# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jyakdi <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/05 20:15:29 by jyakdi            #+#    #+#              #
#    Updated: 2017/05/10 09:42:50 by jyakdi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY : clean, fclean, re, $(NAME)

NAME = wolf3d
SRC = wolf.c ft_image_param.c ft_key_hook.c ft_draw.c event.c ft_readfile.c \
	  ft_line.c ft_draw3d.c ft_instance.c ft_line2.c ft_check_full_map.c
OBJ = $(SRC:.c=.o)
LIBFT = libft/libft.a
CC = gcc
OPTION = -c -I./
MLX = -lmlx -framework OpenGL -framework AppKit
FLAG = -Wall -Werror -Wextra

all : $(NAME)

$(NAME) : $(OBJ)
	@make -Clibft
	@$(CC) -o $(NAME) $(FLAG) $(OBJ) $(LIBFT) $(MLX)

$(OBJ) : $(SRC)
	@$(CC) $(FLAG) $(OPTION)  $(SRC)

clean :
	@make clean -Clibft
	@rm -rf $(OBJ)

fclean : clean
	@make fclean -Clibft
	@rm -rf $(NAME)

re : fclean all
