#include "exibidor.hpp"
void Printer::showClassFile(ClassFile cf) {
    print_magic(cf);
    print_minor_version(cf);
    print_major_version(cf);
    print_cpool_count(cf);
    print_access_flags(cf);
    // print_this_class(cf);
    // print_super_class(cf);
    print_interfaces(cf);
    print_fields(cf);
    // print_methods(cf);
    // print_attributes(cf);
}

void Printer::print_magic(ClassFile cf) {
    std::cout << "Magic: \t";
    std::cout << std::hex << std::showbase << cf.magic << std::endl;
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

void Printer::print_access_flags(ClassFile cf) {
    std::cout << "Access Flags: \t";
    std::cout << std::hex << std::showbase << cf.access_flags << " ";
    switch (cf.access_flags) {
        case AccessFlags::ACC_PUBLIC:
            std::cout << "[public]";
            break;

        case AccessFlags::ACC_PRIVATE:
            std::cout << "[private]";
            break;

        case AccessFlags::ACC_PROTECTED:
            std::cout << "[protected]";
            break;

        case AccessFlags::ACC_STATIC:
            std::cout << "[static]";
            break;

        case AccessFlags::ACC_FINAL:
            std::cout << "[final]";
            break;

        case AccessFlags::ACC_VOLATILE:
            std::cout << "[volatile]";
            break;

        case AccessFlags::ACC_TRANSIENT:
            std::cout << "[transient]";
            break;

        default:
            std::cout << "[error]";
            break;
    };
    std::cout << std::endl;
}

void Printer::print_this_class(ClassFile cf) {
    int cp_info_index = cf.this_class;
    int name_index = cf.constant_pool[cp_info_index].info.class_info.name_index;
    char *thisName = (char *)cf.constant_pool[name_index].info.utf8_info.bytes;
    std::cout << "This class: \t";
    std::cout << "cp_info #";
    std::cout << std::dec << cp_info_index << std::endl;
    std::cout << "<" << thisName << ">" << std::endl;
}

void Printer::print_super_class(ClassFile cf) {
    int cp_info_index = cf.super_class;
    if (cp_info_index == 0) {
        std::cout << "Super class: \t";
        std::cout << "cp_info #-1";
        std::cout << "<Object>" << std::endl;
        return;
    }
    int name_index = cf.constant_pool[cp_info_index].info.class_info.name_index;
    char *thisName = (char *)cf.constant_pool[name_index].info.utf8_info.bytes;
    std::cout << "Super class: \t";
    std::cout << "cp_info #";
    std::cout << std::dec << cp_info_index;
    std::cout << "<" << thisName << ">>" << std::endl;
}

void Printer::print_interfaces(ClassFile cf) {
    std::cout << "Interfaces: \t";
    std::cout << std::dec << cf.interfaces_count << std::endl;
}

void Printer::print_fields(ClassFile cf) {
    std::cout << "Fields: \t";
    std::cout << std::dec << cf.fields_count << std::endl;
}