SRC=main.c
OBJ=$(SRC:.c=.o)
CFLAGS=-fopenmp
BIN=main

all: $(OBJ)

$(OBJ):	$(SRC)
	gcc -o $(BIN) $(CFLAGS) $(SRC)
clean:
	rm -rf *.o
