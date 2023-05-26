NAME			= 	libftprintf.a

SRCS			=	ft_printf.c ft_printf_utils.c

OBJS			=	$(SRCS:.c=.o)

CC				= 	gcc

RM				= 	rm -f

CFLAGS			= 	-Wall -Wextra -Werror

all:			$(NAME)

$(NAME):		$(OBJS)
				@ar -rcs $(NAME) $(OBJS)

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

.PHONY:			all clean fclean re
