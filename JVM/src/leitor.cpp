#include "leitor.hpp"

ClassFile Reader::getClassFile(std::string name) {
    ifstream input(name, ios::binary);
    std::cout << "Nome do Arquivo:" << name << std::endl;

    if (input.is_open()) {
        ClassFile cf = ClassFile();
        input.close();
        return cf;
    } else {
        std::cout << "Não foi possível abrir o arquivo" << std::endl;
        exit(EXIT_FAILURE);
    }
}
