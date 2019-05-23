#include "leitor.hpp"

ClassFile Reader::getClassFile(std::string name) {
    std::cout << name << '\n';
    ifstream input(name, std::ios::binary);

    if (input.is_open()) {
        ClassFile cf = ClassFile();
        input.read((char *)&cf.magic, sizeof(u4));
        cf.magic = htobe32(cf.magic);
        input.read((char *)&cf.minor_version, sizeof(u2));
        cf.minor_version = htobe16(cf.minor_version);
        input.read((char *)&cf.major_version, sizeof(u2));
        cf.major_version = htobe16(cf.major_version);
        input.read((char *)&cf.constant_pool_count, sizeof(u2));
        cf.constant_pool_count = htobe16(cf.constant_pool_count);
        input.close();
        return cf;
    } else {
        exit(EXIT_FAILURE);
    }
}