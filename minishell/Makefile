# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rteles-f <rteles-f@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/09 13:50:32 by rteles-f          #+#    #+#              #
#    Updated: 2023/05/31 18:13:40 by rteles-f         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


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

clean:
			@make clean -s -C src/libft
			@$(RM) $(OBJS)

fclean: clean
			@make fclean -s -C src/libft
			@$(RM) $(NAME)

re: fclean all

norm :
			@norminette -R CheckForbiddenSourceHeader $(SRCS) headers/

m: 			fclean

r:
			make && clear && ./$(NAME)

.PHONY: 	all re clean fclean m