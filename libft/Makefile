SRCS	=	ft_isalnum.c ft_isprint.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_tolower.c \
ft_strlcat.c ft_strncmp.c ft_strlcpy.c ft_strlen.c ft_strnstr.c ft_strjoin.c ft_strdup.c \
ft_strmapi.c  ft_striteri.c  ft_strrchr.c ft_strchr.c ft_strtrim.c ft_putstr_fd.c ft_substr.c \
ft_memcpy.c ft_memmove.c ft_memchr.c ft_memset.c ft_memcmp.c  ft_atoi.c  ft_itoa.c ft_calloc.c \
ft_putendl_fd.c ft_putchar_fd.c ft_bzero.c ft_putnbr_fd.c ft_toupper.c ft_split.c  \

BONUS_SRC	=	ft_lstclear_bonus.c ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstiter_bonus.c \
ft_lstadd_back_bonus.c ft_lstsize_bonus.c ft_lstmap_bonus.c ft_lstdelone_bonus.c ft_lstlast_bonus.c \

OBJS = $(SRCS:.c=.o)

BONUS_OBJS = $(BONUS_SRC:.c=.o)

CC				= cc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror -I.

NAME			= libft.a

all:			$(NAME)

$(NAME):		$(OBJS)
				ar rcs $(NAME) $(OBJS)

clean:
				$(RM) $(OBJS) $(BONUS_OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

bonus:			$(OBJS) $(BONUS_OBJS)
				ar rcs $(NAME) $(OBJS) $(BONUS_OBJS)

.PHONY:			all clean fclean re bonus
