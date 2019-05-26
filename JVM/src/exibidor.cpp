#include "exibidor.hpp"

void Printer::showClassFile(ClassFile cf) {
    print_magic(cf);
    print_minor_version(cf);
    print_major_version(cf);
    print_cpool_count(cf);
    print_access_flags(cf);
    print_this_class(cf);
    print_super_class(cf);
    print_fields_count(cf);
    print_methods_count(cf);
    print_interfaces_count(cf);
    print_attributes_count(cf);
    print_constant_pool(cf);
    print_interfaces(cf);
    print_methods(cf);
    //print_attributes(cf);
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
    int cp_info_index = cf.this_class;
    int name_index =
        cf.constant_pool[cp_info_index].info.class_info.name_index - 2;
    char *thisName = (char *)cf.constant_pool[name_index].info.utf8_info.bytes;
    std::cout << "This class: \t";
    std::cout << "cp_info #";
    std::cout << std::dec << cp_info_index;
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

void Printer::print_interfaces_count(ClassFile cf) {
    std::cout << "Interfaces: \t";
    std::cout << std::dec << cf.interfaces_count << std::endl;
}

void Printer::print_interfaces(ClassFile cf) {
    if (cf.interfaces_count > 0) {
        for (int i = 0; i < cf.interfaces_count; i++) {
            std::cout << "Interface " << i << ":" << std::endl;
            std::cout << cf.interfaces[i] << std::endl;
        }
    }
}

void Printer::print_fields_count(ClassFile cf) {
    std::cout << "Fields: \t";
    std::cout << std::dec << cf.fields_count << std::endl;
}

void Printer::print_methods_count(ClassFile cf) {
    std::cout << "Methods: \t";
    std::cout << std::dec << cf.methods_count << std::endl;
}

void Printer::print_methods(ClassFile cf) {
    std::cout << cf.methods_count << std::endl;
    if (cf.methods_count > 0) {
        for (int i = 0; i < cf.methods_count; i++) {
            // struct method_info {
            //     u2 access_flags;
            //     u2 name_index;
            //     u2 descriptor_index;
            //     u2 attributes_count;
            //     attribute_info *attributes;
            // };

            std::cout << "Method " << i << ":" << std::endl;
            std::cout << cf.methods[i].access_flags << std::endl;
            std::cout << cf.methods[i].name_index << std::endl;
            std::cout << cf.methods[i].descriptor_index << std::endl;
            std::cout << cf.methods[i].attributes_count << std::endl;
        }
    }
}

void Printer::print_attributes_count(ClassFile cf) {
    std::cout << "Attributes: \t";
    std::cout << std::dec << cf.attributes_count << std::endl;
}

void Printer::getIndex_Utf8_Ref(cp_info *constant_pool, u2 index) {
    cp_info *cp = constant_pool + index - 1;
    float aux = 0;

    if (cp->tag == 1) {
        std::cout << cp->info.utf8_info.bytes;
    } else {
        switch (cp->tag) {
            case (ConstantPoolTags::CONSTANT_Float):
                memcpy(&aux, &(cp->info.float_info.bytes), sizeof(float));
                std::cout << aux;
                break;
            case (ConstantPoolTags::CONSTANT_Class):
                getIndex_Utf8_Ref(constant_pool,
                                  cp->info.class_info.name_index);
                break;
            case (ConstantPoolTags::CONSTANT_Fieldref):
                getIndex_Utf8_Ref(constant_pool,
                                  cp->info.fieldref_info.class_index);
                std::cout << ".";
                getIndex_Utf8_Ref(constant_pool,
                                  cp->info.fieldref_info.name_and_type_index);
                break;
            case (ConstantPoolTags::CONSTANT_Methodref):
                getIndex_Utf8_Ref(constant_pool,
                                  cp->info.methodref_info.class_index);
                std::cout << ".";
                getIndex_Utf8_Ref(constant_pool,
                                  cp->info.methodref_info.name_and_type_index);
                break;
            case (ConstantPoolTags::CONSTANT_NameAndType):
                getIndex_Utf8_Ref(constant_pool,
                                  cp->info.nameandtype_info.name_index);
                std::cout << ".";
                getIndex_Utf8_Ref(constant_pool,
                                  cp->info.nameandtype_info.descriptor_index);
                break;
            case (ConstantPoolTags::CONSTANT_String):
                getIndex_Utf8_Ref(constant_pool,
                                  cp->info.string_info.string_index);
                break;
            case (ConstantPoolTags::CONSTANT_InterfaceMethodref):
                getIndex_Utf8_Ref(constant_pool,
                                  cp->info.interfacemethodref_info.class_index);
                std::cout << ".";
                getIndex_Utf8_Ref(
                    constant_pool,
                    cp->info.interfacemethodref_info.name_and_type_index);
                break;
            default:
                break;
        }
    }
}

void Printer::print_constant_pool(ClassFile cf) {
    printf("--------------------++>>CONSTANT POOL\n");
    u1 tag;
    for (int i = 0; i < cf.cp_count - 1; i++) {
        tag = cf.constant_pool[i].tag;
        switch (tag) {
            case ConstantPoolTags::CONSTANT_Class:
                std::cout << "{"<<i+1<<"}" << "CONSTANT_Class\t" <<"name_index: #"<< cf.constant_pool[i].info.class_info.name_index << "->";
                getIndex_Utf8_Ref(cf.constant_pool, cf.constant_pool[i].info.class_info.name_index);
                break;
            case ConstantPoolTags::CONSTANT_Fieldref:
                std::cout << "{"<< i+1 <<"}" << "CONSTANT_Fieldref\t" <<"class_index: #"<< cf.constant_pool[i].info.fieldref_info.class_index << "\tname_and_type_index: #"<< cf.constant_pool[i].info.fieldref_info.name_and_type_index<< " ->";
                getIndex_Utf8_Ref(cf.constant_pool, cf.constant_pool[i].info.fieldref_info.class_index);
                getIndex_Utf8_Ref(cf.constant_pool, cf.constant_pool[i].info.fieldref_info.name_and_type_index);
                break;
            case ConstantPoolTags::CONSTANT_Methodref:
                std::cout << "{"<< i+1 <<"}" << "CONSTANT_Methodref_info\t" <<"class_index: #"<< cf.constant_pool[i].info.methodref_info.class_index << "\tname_and_type_index: #"<< cf.constant_pool[i].info.methodref_info.name_and_type_index<< " ->";
                getIndex_Utf8_Ref(cf.constant_pool, cf.constant_pool[i].info.methodref_info.class_index);
                getIndex_Utf8_Ref(cf.constant_pool, cf.constant_pool[i].info.methodref_info.name_and_type_index);
                break;
            case ConstantPoolTags::CONSTANT_InterfaceMethodref:
                std::cout << "{"<< i+1 <<"}" << "CONSTANT_InterfaceMethodref_info\t" <<"class_index: #"<< cf.constant_pool[i].info.interfacemethodref_info.class_index << "\tname_and_type_index: #"<< cf.constant_pool[i].info.interfacemethodref_info.name_and_type_index<< " ->";
                getIndex_Utf8_Ref(cf.constant_pool, cf.constant_pool[i].info.interfacemethodref_info.class_index);
                getIndex_Utf8_Ref(cf.constant_pool, cf.constant_pool[i].info.interfacemethodref_info.name_and_type_index);
                break;

            case ConstantPoolTags::CONSTANT_String:
                std::cout << "{"<< i+1 <<"}" << "CONSTANT_String_info\t" <<"string_index: #"<< cf.constant_pool[i].info.string_info.string_index << " ->";
                getIndex_Utf8_Ref(cf.constant_pool, cf.constant_pool[i].info.string_info.string_index);
                break;
            case ConstantPoolTags::CONSTANT_Integer:
                std::cout << "{"<< i+1 <<"}" << "CONSTANT_Integer_info\t" <<"bytes: "<< (u4)cf.constant_pool[i].info.integer_info.bytes;
                break;
            /*case ConstantPoolTags::CONSTANT_Float:
                float aux;
                memcpy(&aux, &(cf.constant_pool[i].info.float_info.bytes), sizeof(float));
                std::cout << "{"<< i+1 <<"}" << "CONSTANT_Float:\t" << aux << std::endl;
                break;
            case ConstantPoolTags::CONSTANT_Double:
                double auxd;
                memcpy(&auxd, &(cf.constant_pool[i].info.double_info.bytes), sizeof(double));
                std::cout << "{"<< i+1 <<"}" << "CONSTANT_Double:\t" << auxd << std::endl;
                break;*/
            case ConstantPoolTags::CONSTANT_NameAndType:
                std::cout << "{"<< i+1 <<"}" <<"CONSTANT_NameAndType\t" <<"name_index: "<< cf.constant_pool[i].info.nameandtype_info.name_index <<"\tdescriptor_index:" << cf.constant_pool[i].info.nameandtype_info.descriptor_index;
                getIndex_Utf8_Ref(cf.constant_pool, cf.constant_pool[i].info.nameandtype_info.name_index);
                getIndex_Utf8_Ref(cf.constant_pool, cf.constant_pool[i].info.nameandtype_info.descriptor_index);
                std::cout << std::endl;
                break;
            case ConstantPoolTags::CONSTANT_Utf8:
                std::cout << "{"<< i+1 <<"}" << "CONSTANT_Utf8\t" << cf.constant_pool[i].info.utf8_info.bytes;
                break;
            default:break;
        }
        std::cout << std::endl;

    }
    printf("--------------------++>>CONSTANT POOL\n");
}

void print_attribute(ClassFile, attribute_info, int);
void print_attribute_info(ClassFile, u1);

void Printer::print_attributes(ClassFile cf) {
    std::cout << "########################\n### Class Attributes "
                 "###|\n########################"
              << std::endl;
    std::cout << "Count: " << std::dec << cf.attributes_count << std::endl;
    for (int i = 0; i < cf.attributes_count; i++) {
        print_attribute(cf, cf.attributes[i], i);
    }
}

void print_attribute(ClassFile cf, attribute_info attr, int index) {
    int name_index = attr.attribute_name_index;
    int length = attr.attribute_length;

    std::cout << "[" << std::dec << index << "]" << endl;
    std::cout << "\tAttribute name index:\t"
              << "cp_info#" << std::dec << name_index << " "
              << cf.constant_pool[name_index].info.utf8_info.bytes << endl;
    std::cout << "\tAttribute length:\t" << length << endl;
    std::cout << "\tAttribute Info..:" << endl;
    for (u1 i = 0; i < attr.attribute_length; i++) {
        print_attribute_info(cf, attr.info[i]);
    }
}

void print_attribute_info(ClassFile cf, u1 index_cp) {
    cp_info cp = cf.constant_pool[index_cp];
    cout << "\t\tcp_info#" << std::dec << (u4)cp.tag << " ";
    switch (cp.tag) {
        case ConstantPoolTags::CONSTANT_Class:
            Printer::getIndex_Utf8_Ref(cf.constant_pool,
                                       cp.info.class_info.name_index);
            break;
        case ConstantPoolTags::CONSTANT_Fieldref:
            Printer::getIndex_Utf8_Ref(cf.constant_pool,
                                       cp.info.nameandtype_info.name_index);
            break;
        case ConstantPoolTags::CONSTANT_NameAndType:
            Printer::getIndex_Utf8_Ref(cf.constant_pool,
                                       cp.info.nameandtype_info.name_index);
            break;
        case ConstantPoolTags::CONSTANT_Methodref:
            Printer::getIndex_Utf8_Ref(
                cf.constant_pool, cp.info.methodref_info.name_and_type_index);
            break;
        case ConstantPoolTags::CONSTANT_InterfaceMethodref:
            Printer::getIndex_Utf8_Ref(
                cf.constant_pool,
                cp.info.interfacemethodref_info.name_and_type_index);
            break;
        case ConstantPoolTags::CONSTANT_String:
            Printer::getIndex_Utf8_Ref(
                cf.constant_pool,
                cp.info.interfacemethodref_info.name_and_type_index);
            break;
        case ConstantPoolTags::CONSTANT_Integer:
            break;
    }
    std::cout << std::endl;
}
