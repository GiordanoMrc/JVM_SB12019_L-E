#include "leitor.hpp"

ClassFile Reader::getClassFile(std::string name) {
    std::cout << name << '\n';
    ifstream input(name, std::ios::binary);

    if (input.is_open()) {
        ClassFile cf = ClassFile();
        read_magic(input, &cf);
        read_minor_version(input, &cf);
        read_major_version(input, &cf);
        read_constant_pool(input, &cf);
        input.close();
        return cf;
    } else {
        exit(EXIT_FAILURE);
    }
}

void Reader::read_magic(ifstream &file, ClassFile *cf) {
    file.read((char *)&cf->magic, sizeof(u4));
    cf->magic = htobe32(cf->magic);
}

void Reader::read_minor_version(ifstream &file, ClassFile *cf) {
    file.read((char *)&cf->minor_version, sizeof(u2));
    cf->minor_version = htobe16(cf->minor_version);
}
void Reader::read_major_version(ifstream &file, ClassFile *cf) {
    file.read((char *)&cf->major_version, sizeof(u2));
    cf->major_version = htobe16(cf->major_version);
}
void Reader::read_constant_pool(ifstream &file, ClassFile *cf) {
    file.read((char *)&cf->constant_pool_count, sizeof(u2));
    cf->constant_pool_count = htobe16(cf->constant_pool_count);
}