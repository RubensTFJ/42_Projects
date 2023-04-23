# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rteles-f <rteles-f@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/10 21:45:53 by rteles-f          #+#    #+#              #
#    Updated: 2023/04/23 10:14:33 by rteles-f         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= 	push_swap

CC			= 	cc #-g -fsanitize=address

CFLAGS		= 	-Wall -Wextra -Werror -Iheaders

RM			= 	rm -f

INCLUDES	= 	-Iheaders/

SRCS		=	src/libft_usual.c src/list_aux.c src/main.c src/moves_a.c src/moves_b.c \
				src/moves_both.c src/push_swap_utils.c src/radix.c src/sorting.c \
				ft_printf/ft_printf.c ft_printf/ft_printf_utils.c

OBJS		= 	$(SRCS:.c=.o)

all: 			$(NAME)

$(NAME):		$(OBJS) 
				@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
				@$(RM) $(OBJS)

fclean: clean
				@$(RM) $(NAME)

re: fclean all

norm :
				@norminette -R CheckForbiddenSourceHeader $(SRCS) headers/

m: 				fclean

r:
				make && clear && ./$(NAME)

.PHONY: 		all re clean fclean m
