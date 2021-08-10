CC = gcc
CFLAGS = -Wall -Wextra -Wall -g -fsanitize=address
RM = rm -f

NAME_S = server
NAME_C = client

SRCS_S = server.c
SRCS_C = client.c
SRCS_S_B = server_bonus.c utils_bonus.c utils2_bonus.c
SRCS_C_B = client_bonus.c utils_bonus.c utils2_bonus.c

OBJS_S = $(SRCS_S:.c=.o)
OBJS_C = $(SRCS_C:.c=.o)
OBJS_S_B = $(SRCS_S_B:.c=.o)
OBJS_C_B = $(SRCS_C_B:.c=.o)

all: $(NAME_S) $(NAME_C)

$(NAME_S) :
	CC $(CFLAGS) $(SRCS_S) -o $(NAME_S)

$(NAME_C) :
	CC $(CFLAGS) $(SRCS_C) -o $(NAME_C)

bonus:
	CC $(CFLAGS) $(SRCS_S_B) -o $(NAME_S)
	CC $(CFLAGS) $(SRCS_C_B) -o $(NAME_C)

clean: 
	$(RM) $(OBJS_S)
	$(RM) $(OBJS_C)

fclean:	clean
		$(RM) $(NAME_S)
		$(RM) $(NAME_C)

re:	fclean all