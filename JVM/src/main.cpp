#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include <string>

#include "class_file.hpp"
#include "exibidor.hpp"
#include "leitor.hpp"

using namespace std;

int main(int argc, char *argv[]) {
    string fileName = std::string("./examples/MainOnly.class");
    ClassFile cf = Reader::getClassFile(fileName);
    return EXIT_SUCCESS;
}
