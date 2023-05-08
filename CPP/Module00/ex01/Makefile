# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rteles-f <rteles-f@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/05 19:58:41 by rteles-f          #+#    #+#              #
#    Updated: 2023/05/05 20:00:02 by rteles-f         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= 	PhoneBook

CC			= 	c++ #-g -fsanitize=address

CFLAGS		= 	-Wall -Wextra -Werror -std=c++98

RM			= 	rm -f

INCLUDES	= 	-I

SRCS		=	Main.cpp Contact.cpp PhoneBook.cpp

OBJS		= 	$(SRCS:.cpp=.o)

all: 		$(NAME)

$(NAME):	$(OBJS) 
			@$(CC) $(INCLUDES) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
			@$(RM) $(OBJS)

fclean: 	clean
				@$(RM) $(NAME)

re: 		 all

norm :
			@norminette -R CheckForbiddenSourceHeader $(SRCS) headers/

m: 			fclean

r:
			make && clear && ./$(NAME)

.PHONY: 	all re clean fclean m
