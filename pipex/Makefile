# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rteles-f <rteles-f@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/10 21:45:53 by rteles-f          #+#    #+#              #
#    Updated: 2023/05/08 23:02:52 by rteles-f         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= 	pipex

CC			= 	cc #-g -fsanitize=address

CFLAGS		= 	-Wall -Wextra -Werror -Iheaders/ -g

RM			= 	rm -f

INCLUDES	= 	-Iheaders/

SRCS		=	src/end_program.c src/here_doc.c src/main.c src/pipex.c \
				src/utils/ft_printf.c src/utils/ft_printf_utils.c \
				src/utils/get_next_line.c src/utils/ft_split.c src/utils/libft_usual.c

OBJS		= 	$(SRCS:.c=.o)

all: 		$(NAME)

$(NAME):	$(OBJS) 
			@$(CC) $(INCLUDES) $(CFLAGS) $(OBJS) -o $(NAME)

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
