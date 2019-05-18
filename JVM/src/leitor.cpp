#include "leitor.hpp"

ClassFile Reader::getClassFile(std::string name) {
    std::ifstream input(name, std::ios::binary);
    ClassFile cf = ClassFile();
    this->read_magic(cf);
    this->input.close();
}

void Reader::read_magic(ClassFile cf) {
    input.read((char *)cf.magic, sizeof(u4));
}