#include "exibidor.hpp"

void Printer::showClassFile(ClassFile cf) { Printer::print_magic(cf); }

void Printer::print_magic(ClassFile cf) {
    std::cout << "Magic: \t";
    std::cout << std::hex << cf.magic;
}