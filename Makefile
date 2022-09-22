NAME = minitalk
SERVER_TARGET = server
CLIENT_TARGET = client


CC = gcc
CFLAG = -Wall -Wextra -Werror
INCLUDE = ./minitalk.h
RM = rm -f
AR = ar rcs

FILES = ft_util.c	\
		ft_strdup.c \
		ft_itoa.c	\
		ft_atoi.c 	\
		ft_binary_parser.c

SERVER_FILES = server.c $(FILES)

CLIENT_FILES = client.c $(FILES)

OBJS = $(FILES:.c=.o)
SERVER_OBJS = $(SERVER_FILES:.c=.o)
CLIENT_OBJS = $(CLIENT_FILES:.c=.o)

all:	$(NAME)

server: $(SERVER_TARGET)

client:	$(CLIENT_TARGET)


$(NAME):	$(OBJS)
	$(CC) -o $@ $^

$(SERVER_TARGET):	$(SERVER_OBJS) $(OBJS)
	$(CC) -o $@ $^

$(CLIENT_TARGET): $(CLIENT_OBJS) $(OBJS)
	$(CC) -o $@ $^

%.o:	%.c
	$(CC) -I$(INCLUDE) -c $< -o $@ -g3

clean:
	$(RM) $(OBJS) $(SERVER_OBJS) $(CLIENT_OBJS)

fclean:	clean
	$(RM) $(NAME) $(SERVER_TARGET) $(CLIENT_TARGET)

re:	fclean

.PHONY : all clean fclean re bonus run server client