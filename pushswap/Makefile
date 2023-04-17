# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rteles-f <rteles-f@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/10 21:45:53 by rteles-f          #+#    #+#              #
#    Updated: 2023/04/14 23:52:01 by rteles-f         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= 	pushswap

CC			= 	cc #-g -fsanitize=address

CFLAGS		= 	-Wall -Wextra -Werror

RM			= 	rm -f

INCLUDES	= 	-Iheaders/

SRCS		=	ft_printf/*.c src/*.c

OBJS		= 	$(SRCS:.c=.o)

all: 		$(NAME)

$(NAME):	$(SRCS) 
			$(CC) $(INCLUDES) $(CFLAGS) $(SRCS) -o $(NAME)

clean:
			@$(RM) $(OBJS)

fclean: clean
			@$(RM) $(NAME)

re: fclean all

norm :
			@norminette -R CheckForbiddenSourceHeader $(SRCS) headers/

m: 			fclean

r:
			make && clear && ./$(NAME)

.PHONY: 	all re clean fclean m
