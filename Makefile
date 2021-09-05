CLIENT_FILES	=	client.c \
					ft_atoi.c \
					utils.c \

SERVER_FILES	=	server.c \
					ft_putnbr_fd.c \
					utils.c

HEADS			=	app.h

GCC             =   gcc
OBJS_SERVER     =   $(SERVER_FILES:.c=.o)
OBJS_CLIENT     =   $(CLIENT_FILES:.c=.o)
FLAGS           =   -Wall -Wextra -Werror
NAME_SERV       =   server
NAME_CLI	    =   client

.c.o:
	${GCC} ${FLAGS} -c $< -o $@

all: $(NAME_SERV) $(NAME_CLI)

$(NAME_SERV): $(OBJS_SERVER) $(HEADS)
	$(GCC) $(FLAGS) $(OBJS_SERVER) -o $(NAME_SERV)

$(NAME_CLI): $(OBJS_CLIENT) $(HEADS)
	$(GCC) $(FLAGS) $(OBJS_CLIENT) -o $(NAME_CLI)

clean:
	rm -rf $(OBJS_CLIENT) $(OBJS_SERVER)

fclean: clean
	rm -rf $(NAME_SERV) $(NAME_CLI)

re: fclean all

.PHONY: all, re, clean, $(NAME_SERV), $(NAME_CLI), fclean