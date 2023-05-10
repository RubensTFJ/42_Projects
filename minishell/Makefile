# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rteles-f <rteles-f@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/09 13:50:32 by rteles-f          #+#    #+#              #
#    Updated: 2023/05/09 13:51:44 by rteles-f         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME		= 	minishell

CC			= 	cc #-g -fsanitize=address

CFLAGS		= 	-Wall -Wextra -Werror -Iheaders/ -pthread -g

RM			= 	rm -f

# INCLUDES	= 	-Iheaders/

SRCS		=	src/*.c src/*/*.c

OBJS		= 	$(SRCS:.c=.o)

all: 		$(NAME)

$(NAME):	$(SRCS) 
			@$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

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