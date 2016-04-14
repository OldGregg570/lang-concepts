CC     = gcc
CFLAGS = -g
RM     = rm -f

default: fibonacci

fibonacci: ./src/fibonacci.c
	$(CC) $(CFLAGS) -o ./bin/fibonacci ./src/utils.h ./src/fibonacci.c

clean:
	$(RM) ./bin/fibonacci
