CC     = gcc
CFLAGS = -g
RM     = rm -f
UTILS  = ./src/utils.h


default: fibonacci

fibonacci: ./src/fibonacci.c
	$(CC) $(CFLAGS) -o ./bin/fibonacci ${UTILS} ./src/fibonacci.c

factorial: ./src/factorial.c
	$(CC) $(CFLAGS) -o ./bin/factorial ${UTILS} ./src/factorial.c

collatz: ./src/collatz.c
	$(CC) $(CFLAGS) -o ./bin/collatz ${UTILS} ./src/collatz.c

all: fibonacci factorial collatz

clean:
	$(RM) ./bin/**

run:
	./bin/fibonacci
	./bin/factorial
	./bin/collatz
