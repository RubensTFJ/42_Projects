# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rteles-f <rteles-f@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/10 21:45:53 by rteles-f          #+#    #+#              #
#    Updated: 2023/05/02 20:26:14 by rteles-f         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= 	philosophers

CC			= 	cc #-g -fsanitize=address

CFLAGS		= 	-Wall -Wextra -Werror -g

RM			= 	rm -f

INCLUDES	= 	-Iheaders/

SRCS		=	src/*.c

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
