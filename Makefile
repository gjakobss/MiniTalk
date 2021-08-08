CC = gcc
CFLAGS = -Wall -Wextra -Wall
RM = rm -f

NAME_S = server
NAME_C = client

SRCS_S = server.c
SRCS_C = client.c

OBJS_S = $(SRCS_S:.c=.o)
OBJS_C = $(SRCS_C:.c=.o)

all: $(NAME_S) $(NAME_C)

$(NAME_S) :
	CC $(CFLAGS) $(SRCS_S) -o $(NAME_S)

$(NAME_C) :
	CC $(CFLAGS) $(SRCS_C) -o $(NAME_C)

clean: 
	$(RM) $(OBJS_S)
	$(RM) $(OBJS_C)

fclean:	clean
		$(RM) $(NAME_S)
		$(RM) $(NAME_C)

re:	fclean all