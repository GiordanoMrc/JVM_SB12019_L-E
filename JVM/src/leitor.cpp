#include "leitor.hpp"

long int getSizeofConstant(int tag);

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
    cf->magic = CorrectEndian::t_u4(cf->magic);
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
    u1 tag_reader = 0;
    file.read((char *)&cf->constant_pool_count, sizeof(u2));
    cf->constant_pool_count = htobe16(cf->constant_pool_count);
    cf->constant_pool =
        (cp_info *)calloc(sizeof(cp_info), cf->constant_pool_count - 1);
    for (int i = 0; i < cf->constant_pool_count; i++) {
        file.read((char *)&tag_reader, sizeof(u1));
        cf->constant_pool[i].tag = tag_reader;
        file.read((char *)&cf->constant_pool[0].info,
                  getSizeofConstant(tag_reader));
    }
}

long int getSizeofConstant(int tag) {
    switch (tag) {
        case CONSTANT_Methodref:
            return sizeof(CONSTANT_Methodref_info);
            break;
        default:
            exit(EXIT_FAILURE);
            break;
    }
}