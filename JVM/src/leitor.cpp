#include "leitor.hpp"

ClassFile Reader::getClassFile(std::string name) {
    std::cout << name << '\n';
    std::ifstream input(name, std::ios::binary);
    if (input.is_open()) {
        ClassFile cf = ClassFile();
        this->read_magic(&cf);
        this->input.close();
        return cf;
    } else {
        exit(EXIT_FAILURE);
    }
}

void Reader::read_magic(ClassFile *cf) {
    input.read((char *)&cf->magic, sizeof(u4));
}