CC=g++
CFLAGS=-Wall -std=c++11 -g -o0
C_SRCS := $(wildcard *.cpp)

DIR_SRC=src/
DIR_OBJ=build/

_OBJ= main.o leitor.o exibidor.o data_type.o
OBJ = $(patsubst %,$(DIR_OBJ)%,$(_OBJ))

all : clean compile exec

exec :
	@echo "Começando a execução da Poor Man's JVM:"
	@build/./main
	@echo "Terminando a Execução."

$(DIR_OBJ)%.o: $(DIR_SRC)%.cpp
	@$(CC) $(CFLAGS) -c -o $@ $< -Iincludes

compile: $(OBJ)
	@$(CC) $(CFLAGS) -o build/main $^ -Iincludes

clean :
	@rm -rf build
	@mkdir build
