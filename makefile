CC     = gcc
CFLAGS = -g
RM     = rm -f
INCLUDES  = ./include/utils.h ./include/fibonacci.h ./include/hash-table.h


default: encoder

encoder: ./src/fib-encoder.c
	$(CC) $(CFLAGS) -o ./bin/fib-encoder ${INCLUDES} ./src/fib-encoder.c

polycalc: ./src/poly-calculator.c
	${CC} ${CFLAGS} -o ./bin/poly-calculator ${INCLUDES} ./src/poly-calculator.c

all: encoder polycalc

clean:
	$(RM) ./bin/**

run:
	./bin/fib-encoder
	./bin/poly-calculator

fib: all
	./bin/fib-encoder

poly: all
	./bin/poly-calculator
