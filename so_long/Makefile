# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rteles-f <rteles-f@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/10 21:45:53 by rteles-f          #+#    #+#              #
#    Updated: 2023/03/17 22:25:26 by rteles-f         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= 	so_long
CC			= 	gcc -Wall -Wextra -Werror # -g -fsanitize=address
RM			= 	/bin/rm -f
INCLUDES	= 	-Iheaders/

SRCS		=	$(shell find src/ -name *.c) 
OBJS		= 	$(SRCS:.c=.o)

MLX_LIB_DIR = mlx_linux/
LIBFT_INCLUDE = -ILIBFT/include
MLX_INCLUDE = -Imlx_linux
MLX_FLAGS = -L$(MLX_LIB_DIR) -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz


all: $(NAME)

$(NAME): $(OBJS) 
	@$(MAKE) -s -C mlx_linux
	@$(CC) $(^) $(MLX_FLAGS) -o $(@)

%.o: %.c $(MLX_LIB)
	@$(CC) $(INCLUDES) $(MLX_INCLUDE) -c $(^) -o $(@)

clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

norm :
	@norminette -R CheckForbiddenSourceHeader $(SRCS) headers/

m: fclean

r:
	make && clear && ./$(NAME) map.ber

.PHONY: all re clean fclean m