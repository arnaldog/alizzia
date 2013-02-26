#Compilador
CC=g++
#Flags que usara el compilador
CFLAGS=-c -Wall
#Ejecutable
BIN=RealNumber.bin
INC=-I/lib
SRC=Main.cpp RealNumber.cpp
OBJ=$(SRC:.cpp=.o)

all: $(BIN)

$(BIN): $(OBJ)
	$(CC) $(OBJ) -o $(BIN) -lm

clean:
	rm -rf $(BIN) $(OBJ) 
