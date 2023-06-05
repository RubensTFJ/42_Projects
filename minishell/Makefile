# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rteles-f <rteles-f@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/09 13:50:32 by rteles-f          #+#    #+#              #
#    Updated: 2023/06/05 19:57:35 by rteles-f         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

COLOR_RESET =	\033[0m
COLOR_GREEN =	\033[32m
CLEAR		=	\033[H\033[2J

NAME		= 	minishell

CC			= 	cc #-g -fsanitize=address

CFLAGS		=  -Wall -Wextra -Werror $(INCLUDES)

RM			= 	rm -f

INCLUDES	= 	-Iheaders/ -Isrc/libft/libft_includes

SRCS		=	 src/*/*.c

OBJS		= 	$(SRCS:.c=.o)

all: 		$(NAME)

$(NAME):	$(SRCS)
			@make bonus -s -C src/libft
			@$(CC) $(CFLAGS) $(SRCS) src/libft/libft.a -o $(NAME)
			@echo "[$(COLOR_GREEN)info$(COLOR_RESET)]: Minishell Built"

clean:
			@make clean -s -C src/libft
			@$(RM) $(OBJS)
			@echo "[$(COLOR_GREEN)info$(COLOR_RESET)]: Clean"

fclean: 	clean
			@make fclean -s -C src/libft
			@$(RM) $(NAME)
			@echo "[$(COLOR_GREEN)info$(COLOR_RESET)]: Full"

re:			fclean all

norm :
			@norminette -R CheckForbiddenSourceHeader $(SRCS) headers/

r:
			make && clear && ./$(NAME)

.PHONY: 	all re clean fclean