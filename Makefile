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
		ft_atoi.c

SERVER_FILES = server.c $(FILES)
CLIENT_FILES = client.c $(FILES)

OBJS = $(FILES:.c=.o)
SERVER_OBJS = $(SERVER_FILES:.c=.o)
CLIENT_OBJS = $(CLIENT_FILES:.c=.o)

all:	server client

server: $(SERVER_TARGET)

client:	$(CLIENT_TARGET)

$(SERVER_TARGET):	$(SERVER_OBJS) $(OBJS)
	$(CC) $(CFLAG) -o $@ $^

$(CLIENT_TARGET): $(CLIENT_OBJS) $(OBJS)
	$(CC) $(CFLAG) -o $@ $^

%.o:	%.c
	$(CC) $(CFLAG) -I$(INCLUDE) -c $< -o $@ -g3

clean:
	$(RM) $(OBJS) $(SERVER_OBJS) $(CLIENT_OBJS)

fclean:	clean
	$(RM) $(SERVER_TARGET) $(CLIENT_TARGET)

re:	fclean

.PHONY : all clean fclean re run server client