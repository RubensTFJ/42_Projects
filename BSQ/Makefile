
NAME := bsq
SRCFOLDER := src
OBJSNAMES := bsq.o mapread.o printtable.o errorhandling.o main.o
OBJS := $(addprefix $(SRCFOLDER)/,$(OBJSNAMES))

all: $(NAME)

$(NAME): $(OBJS)
	gcc -Wall -Wextra -Werror $(OBJS) -o $(NAME)

$(OBJS): %.o: %.c
	gcc -Wall -Wextra -Werror -c $< -o $@
	gcc -Wall -Wextra -Werror -c $(addprefix $(SRCFOLDER)/,bsqheader.h) -o bsqheader.o

clean:
	rm -f $(OBJS)

fclean:
	rm -f $(OBJS)
	rm -f $(NAME)

re: fclean all

.PHONY = all clean fclean re