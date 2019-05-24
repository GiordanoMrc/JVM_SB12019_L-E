#include "exibidor.hpp"
void Printer::showClassFile(ClassFile cf) {
    print_magic(cf);
    print_minor_version(cf);
    print_major_version(cf);
    print_cpool_count(cf);
}

void Printer::print_magic(ClassFile cf) {
    std::cout << "Magic: \t0x";
    printf("%x\n", cf.magic);
}

void Printer::print_minor_version(ClassFile cf) {
    std::cout << "Minor Version: \t";
    std::cout << std::dec << cf.minor_version << std::endl;
}

void Printer::print_major_version(ClassFile cf) {
    std::cout << "Major Version: \t";
    std::cout << std::dec << cf.major_version << std::endl;
}

void Printer::print_cpool_count(ClassFile cf) {
    std::cout << "Constant Pool Count: \t";
    std::cout << std::dec << cf.cp_count << std::endl;
}