#Compilador
CC=g++
#Flags que usara el compilador
CFLAGS=-c -Wall
#Ejecutable
BIN=RealNumber.bin
INC=-I/lib
FLAGS=-fopenmp
SRC=Main.cpp RealNumber.cpp
OBJ=$(SRC:.cpp=.o)

all:
	$(CC)  -o $(BIN) $(FLAGS) $(SRC) -lm

clean:
	rm -rf $(BIN) $(OBJ) 
