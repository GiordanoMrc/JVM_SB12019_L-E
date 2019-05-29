#include "exibidor.hpp"

void Printer::showClassFile(ClassFile cf) {
    print_magic(cf);
    print_minor_version(cf);
    print_major_version(cf);
    print_constant_pool_count(cf);
    print_access_flags(cf);
    print_this_class(cf);
    print_super_class(cf);
    print_fields_count(cf);
    print_methods_count(cf);
    print_interfaces_count(cf);
    print_attributes_count(cf);
    // print_constant_pool(cf);
    // print_interfaces(cf);
    // print_fields(cf);
    // print_methods(cf);
    // print_attributes(cf);
}

void Printer::print_magic(ClassFile cf) {
    std::cout << "Magic: \t\t\t";
    std::cout << std::hex << std::showbase << cf.magic << std::endl;
}

void Printer::print_minor_version(ClassFile cf) {
    std::cout << "Minor Version: \t\t";
    std::cout << std::dec << cf.minor_version << std::endl;
}

void Printer::print_major_version(ClassFile cf) {
    std::cout << "Major Version: \t\t";
    std::cout << std::dec << cf.major_version << std::endl;
}

void Printer::print_constant_pool_count(ClassFile cf) {
    std::cout << "Constant Pool Count: \t";
    std::cout << std::dec << cf.cp_count << std::endl;
}

void Printer::print_access_flags(ClassFile cf) {
    std::cout << "Access Flags: \t\t";
    std::cout << std::hex << std::showbase << cf.access_flags << " ";
    std::cout << "[";
    if (cf.access_flags & AccessFlags::PUBLIC) {
        std::cout << " public ";
    }
    if (cf.access_flags >> 1 & AccessFlags::FINAL >> 1) {
        std::cout << " final ";
    }
    if (cf.access_flags >> 1 & AccessFlags::SUPER >> 1) {
        std::cout << " super ";
    }
    if (cf.access_flags >> 2 & AccessFlags::INTERFACE >> 2) {
        std::cout << " interface ";
    }
    if (cf.access_flags & AccessFlags::ABSTRACT) {
        std::cout << " abstract ";
    }
    if (cf.access_flags & AccessFlags::SYNTHETIC) {
        std::cout << " synthetic ";
    }
    if (cf.access_flags & AccessFlags::ANNOTATION) {
        std::cout << " annotation ";
    }
    if (cf.access_flags & AccessFlags::ENUM) {
        std::cout << " enum ";
    }
    std::cout << "]";
    std::cout << std::endl;
}

void Printer::print_this_class(ClassFile cf) {
    // The constant_pool table is indexed from 1 to constant_pool_count - 1.
    int cp_info_index = correct_index(cf.this_class);
    int name_index = correct_index(
        cf.constant_pool[cp_info_index].info.class_info.name_index);
    u1 *thisName = cf.constant_pool[name_index].info.utf8_info.bytes;
    std::cout << "This class: \t\t";
    std::cout << "cp_info #";
    std::cout << std::dec << cp_info_index;
    std::cout << "<" << thisName << ">" << std::endl;
}

void Printer::print_super_class(ClassFile cf) {
    int cp_info_index = cf.super_class;
    // If the value of the super_class item is zero,
    // then this class file must represent the class Object,
    // the only class or interface without a direct superclass.
    if (cp_info_index == 0) {
        std::cout << "Super class: \t\t";
        std::cout << "cp_info ##";
        std::cout << "<java/lang/Object>" << std::endl;
        return;
    }
    // The constant_pool table is indexed from 1 to constant_pool_count - 1.
    cp_info_index = correct_index(cf.super_class);
    int name_index = correct_index(
        cf.constant_pool[cp_info_index].info.class_info.name_index);
    u1 *superName = cf.constant_pool[name_index].info.utf8_info.bytes;
    std::cout << "Super class: \t\t";
    std::cout << "cp_info #";
    std::cout << std::dec << cp_info_index;
    std::cout << "<" << superName << ">" << std::endl;
}

void Printer::print_fields_count(ClassFile cf) {
    std::cout << "Fields Count: \t\t";
    std::cout << std::dec << cf.fields_count << std::endl;
}

void Printer::print_methods_count(ClassFile cf) {
    std::cout << "Methods Count: \t\t";
    std::cout << std::dec << cf.methods_count << std::endl;
}

void Printer::print_interfaces_count(ClassFile cf) {
    std::cout << "Interfaces Count: \t";
    std::cout << std::dec << cf.interfaces_count << std::endl;
}

void Printer::print_attributes_count(ClassFile cf) {
    std::cout << "Attributes Count: \t";
    std::cout << std::dec << cf.attributes_count << std::endl;
}
