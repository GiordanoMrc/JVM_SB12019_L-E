#include "leitor.hpp"

ClassFile Reader::getClassFile(std::string name) {
    ifstream input(name, ios::binary);
    std::cout << "Nome do Arquivo:" << name << std::endl;

    if (input.is_open()) {
        ClassFile cf = ClassFile();
        read_magic(input, &cf);
        read_minor_version(input, &cf);
        read_major_version(input, &cf);
        read_cpool_count(input, &cf);
        read_access_flags(input, &cf);
        input.close();
        return cf;
    } else {
        std::cout << "Não foi possível abrir o arquivo" << std::endl;
        exit(EXIT_FAILURE);
    }
}

void Reader::read_magic(ifstream &file, ClassFile *cf) {
    readt_u4(&cf->magic, file, 1);
}

void Reader::read_minor_version(ifstream &file, ClassFile *cf) {
    readt_u2(&cf->minor_version, file, 1);
}
void Reader::read_major_version(ifstream &file, ClassFile *cf) {
    readt_u2(&cf->major_version, file, 1);
}
void Reader::read_cpool_count(ifstream &file, ClassFile *cf) {
    readt_u2(&cf->cp_count, file, 1);
}
void Reader::read_access_flags(ifstream &file, ClassFile *cf) {
    readt_u2(&cf->access_flags, file, 1);
}
