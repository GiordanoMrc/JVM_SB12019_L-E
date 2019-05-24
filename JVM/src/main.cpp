#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include <string>

#include "class_file.h"
#include "exibidor.hpp"
#include "leitor.hpp"

using namespace std;

int main(int argc, char *argv[]) {
    // string mode, name;

    // if (argc < 3) {
    //     cout << "numero de args invalido";

    // } else {
    //     mode = argv[1];
    //     name = argv[2];
    // }

    // if (mode == "-le") {
    //     cout << mode << "\n" << name;
    // }
    string fileName = std::string("./examples/MainOnly.class");
    ClassFile cf = Reader::getClassFile(fileName);
    Printer::showClassFile(cf);
    return EXIT_SUCCESS;
}
