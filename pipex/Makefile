# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rteles-f <rteles-f@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/10 21:45:53 by rteles-f          #+#    #+#              #
#    Updated: 2023/03/28 23:31:07 by rteles-f         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= 	pipex

CC			= 	cc #-g -fsanitize=address

CFLAGS		= 	-Wall -Wextra -Werror -g

RM			= 	rm -f

INCLUDES	= 	-Iheaders/

SRCS		=	ft_printf/*.c src/*.c

OBJS		= 	$(SRCS:.c=.o)

all: 		$(NAME)

$(NAME):	$(SRCS) 
			@$(CC) $(INCLUDES) $(CFLAGS) $(SRCS) -o $(NAME)

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
