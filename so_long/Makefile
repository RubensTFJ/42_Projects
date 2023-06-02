# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rteles-f <rteles-f@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/06 22:11:29 by rteles-f          #+#    #+#              #
#    Updated: 2023/05/31 17:51:41 by rteles-f         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= 	so_long
CC				= 	gcc -Wall -Wextra -Werror # -g -fsanitize=address
RM				= 	/bin/rm -f
INCLUDES		= 	-Iheaders/
	
SRCS			=	src/end_game.c src/global.c src/image.c src/image_utils.c src/is_map_valid.c \
					src/is_map_valid_utils.c src/main.c src/map_functions.c src/movement.c \
					src/movement_collision.c src/obj_creation.c src/object_types.c src/update_utils.c \
					src/utils/ft_printf.c src/utils/ft_printf_utils.c src/utils/get_next_line.c \
					src/utils/libft_func.c src/utils/list.c

OBJS			= 	$(SRCS:.c=.o)

MLX_LIB_DIR 	=	mlx_linux/
LIBFT_INCLUDE 	=	-ILIBFT/include
MLX_INCLUDE 	=	-Imlx_linux
MLX_FLAGS 		=	-L$(MLX_LIB_DIR) -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz

all: 			$(NAME)

$(NAME): 		$(OBJS)
					@$(MAKE) -s -C mlx_linux
					@$(CC) $(^) $(MLX_FLAGS) -o $(@)

%.o: %.c
				@$(CC) $(INCLUDES) $(MLX_INCLUDE) -c $(^) -o $(@)

clean:
					@$(RM) $(OBJS)

fclean: 		clean
				@$(RM) $(NAME)

re: 			fclean all

norm :
				@norminette -R CheckForbiddenSourceHeader $(SRCS) headers/

m: 				fclean

r:
				make && clear && ./$(NAME) map.ber

.PHONY: 		all re clean fclean m