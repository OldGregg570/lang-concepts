CC     = gcc
CFLAGS = -g
RM     = rm -f

default: fibonacci

fibonacci: ./src/fibonacci.c
	$(CC) $(CFLAGS) -o ./bin/fibonacci ./src/utils.h ./src/fibonacci.c

factorial: ./src/factorial.c
	$(CC) $(CFLAGS) -o ./bin/factorial ./src/utils.h ./src/factorial.c

clean:
	$(RM) ./bin/**
