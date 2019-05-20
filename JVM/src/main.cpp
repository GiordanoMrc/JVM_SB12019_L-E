#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include <string>

#include "exibidor.hpp"
#include "leitor.hpp"
#include "types/class_file.h"

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
    Reader rd = Reader();
    ClassFile cf =
        rd.getClassFile(std::string("/home/santosdanilo/workspace-unb/sb/"
                                    "JVM_SB12019/JVM/examples/MainOnly.class"));
    Printer::showClassFile(cf);
    return EXIT_SUCCESS;
}