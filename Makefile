CFLAGS = -Wall -g 

CC = gcc
RM = rm
BINARY = my_sizeof
SRCS = my_sizeof.c

OBJS = $(SRCS:.c=.o)

all: $(OBJS)
	@$(CC) $(CFLAGS) -o $(BINARY) $(OBJS)
	@echo "\033[1;32m" "[COMPILATION DONE]"  "\033[m"

.c.o:
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) *.o $(BINARY)
