CC=g++
CFLAGS=-Wall -std=c++11
C_SRCS := $(wildcard *.cpp)

DIR_SRC=src/
DIR_OBJ=build/

_OBJ= main.o leitor.o exibidor.o correct_endian.o
OBJ = $(patsubst %,$(DIR_OBJ)%,$(_OBJ))

all : clean compile exec

exec :
	@echo "Running main..."
	@echo "\n"
	@build/./main
	@echo "\n"
	@echo "Done running!"

$(DIR_OBJ)%.o: $(DIR_SRC)%.cpp
	@$(CC) $(CFLAGS) -c -o $@ $< -Iincludes

compile: $(OBJ)
	@echo "Compilando arquivos objetos..."
	@$(CC) $(CFLAGS) -o build/main $^ -Iincludes
	@echo "Compilação concluída!"

clean :
	@rm -rf build
	@mkdir build
	@echo "Arquivos removidos!"
