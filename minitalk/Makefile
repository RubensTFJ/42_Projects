# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rteles-f <rteles-f@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/31 23:39:00 by rteles-f          #+#    #+#              #
#    Updated: 2023/05/08 23:07:40 by rteles-f         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER_NAME		= 	server

CLIENT_NAME		=	client

CC				= 	cc #-g -fsanitize=address

CFLAGS			= 	-Wall -Wextra -Werror -g

RM				= 	rm -f

INCLUDES		= 	-Iheaders/

SRC_SERV		=	ft_printf/*.c src/server.c src/libft_usual.c
	
SRC_CLIENT		=	ft_printf/*.c src/client.c src/libft_usual.c

OBJS			= 	$(SRCS:.c=.o)

all: 		$(SERVER_NAME) $(CLIENT_NAME)

$(SERVER_NAME):	$(SRC_SERV) 
			@$(CC) $(INCLUDES) $(CFLAGS) $(SRC_SERV) -o $(SERVER_NAME)

$(CLIENT_NAME):	$(SRC_CLIENT) 
			@$(CC) $(INCLUDES) $(CFLAGS) $(SRC_CLIENT) -o $(CLIENT_NAME)

clean:
			@$(RM) $(OBJS)

fclean: clean
			@$(RM) $(CLIENT_NAME) $(SERVER_NAME)

re: fclean all

norm :
			@norminette -R CheckForbiddenSourceHeader $(SRCS) headers/

r:
			make && clear && ./$(NAME)

.PHONY: 	all re clean fclean m
