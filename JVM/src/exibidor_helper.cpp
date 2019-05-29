#include "exibidor_helper.hpp"

u1 *get_end_index_utf8_bytes(cp_info *constant_pool, u2 index) {
    cp_info *cp = constant_pool + index - 1;
    float aux = 0;

    if (cp->tag == 1) {
        return cp->info.utf8_info.bytes;
    }
    switch (cp->tag) {
        case (ConstantPoolTags::CONSTANT_Float):
            memcpy(&aux, &(cp->info.float_info.bytes), sizeof(float));
            std::cout << aux;
            break;
        case (ConstantPoolTags::CONSTANT_Class):
            get_end_index_utf8_bytes(constant_pool,
                                     cp->info.class_info.name_index);
            break;
        case (ConstantPoolTags::CONSTANT_Fieldref):
            get_end_index_utf8_bytes(constant_pool,
                                     cp->info.fieldref_info.class_index);
            std::cout << ".";
            get_end_index_utf8_bytes(
                constant_pool, cp->info.fieldref_info.name_and_type_index);
            break;
        case (ConstantPoolTags::CONSTANT_Methodref):
            get_end_index_utf8_bytes(constant_pool,
                                     cp->info.methodref_info.class_index);
            std::cout << ".";
            get_end_index_utf8_bytes(
                constant_pool, cp->info.methodref_info.name_and_type_index);
            break;
        case (ConstantPoolTags::CONSTANT_NameAndType):
            get_end_index_utf8_bytes(constant_pool,
                                     cp->info.nameandtype_info.name_index);
            std::cout << ".";
            get_end_index_utf8_bytes(
                constant_pool, cp->info.nameandtype_info.descriptor_index);
            break;
        case (ConstantPoolTags::CONSTANT_String):
            get_end_index_utf8_bytes(constant_pool,
                                     (u2)cp->info.string_info.string_index);
            break;
        case (ConstantPoolTags::CONSTANT_InterfaceMethodref):
            get_end_index_utf8_bytes(
                constant_pool, cp->info.interfacemethodref_info.class_index);
            std::cout << ".";
            get_end_index_utf8_bytes(
                constant_pool,
                cp->info.interfacemethodref_info.name_and_type_index);
            break;
        case (ConstantPoolTags::CONSTANT_MethodHandle):
            get_end_index_utf8_bytes(
                constant_pool, cp->info.methodhandle_info.reference_index);
            break;
        case (ConstantPoolTags::CONSTANT_MethodType):
            get_end_index_utf8_bytes(constant_pool,
                                     cp->info.methodtype_info.descriptor_index);
            break;
        case (ConstantPoolTags::CONSTANT_InvokeDynamic):
            get_end_index_utf8_bytes(
                constant_pool,
                cp->info.invokedynamic_info.bootstrap_method_attr_index);
            get_end_index_utf8_bytes(
                constant_pool, cp->info.invokedynamic_info.name_and_type_index);
            break;
        default:
            break;
    }
}

void get_Access_Flag_Field1(u2 flag) {
    if (flag & 1) {
        std::cout << "public ";
    }

    if ((flag >> 1) & 0x0001) {
        std::cout << "private ";
    }

    if ((flag >> 2) & 0x0001) {
        std::cout << "protected ";
    }

    if ((flag >> 3) & 0x0001) {
        std::cout << "static ";
    }

    if ((flag >> 4) & 0x0001) {
        std::cout << "final ";
    }

    if ((flag >> 6) & 0x0001) {
        std::cout << "volatile ";
    }

    if ((flag >> 7) & 0x0001) {
        std::cout << "transient ";
    }

    if ((flag >> 13) & 0x0001) {
        std::cout << "synthetic ";
    }

    if ((flag >> 14) & 0x0001) {
        std::cout << "enum ";
    }
}

void get_Access_Flag_Field2(u2 flag) {
    bool imprimiu = false;

    if (flag & 1) {
        std::cout << "ACC_PUBLIC";
        imprimiu = true;
    }

    if ((flag >> 1) & 0x0001) {
        if (imprimiu) {
            std::cout << ", ";
        }
        std::cout << "ACC_PRIVATE";
        imprimiu = true;
    }

    if ((flag >> 2) & 0x0001) {
        if (imprimiu) {
            std::cout << ", ";
        }
        std::cout << "ACC_PROTECTED";
        imprimiu = true;
    }

    if ((flag >> 3) & 0x0001) {
        if (imprimiu) {
            std::cout << ", ";
        }
        std::cout << "ACC_STATIC";
        imprimiu = true;
    }

    if ((flag >> 4) & 0x0001) {
        if (imprimiu) {
            std::cout << ", ";
        }
        std::cout << "ACC_FINAL";
        imprimiu = true;
    }

    if ((flag >> 6) & 0x0001) {
        if (imprimiu) {
            std::cout << ", ";
        }
        std::cout << "ACC_VOLATILE";
        imprimiu = true;
    }

    if ((flag >> 7) & 0x0001) {
        if (imprimiu) {
            std::cout << ", ";
        }
        std::cout << "ACC_TRANSIENT";
        imprimiu = true;
    }

    if ((flag >> 13) & 0x0001) {
        if (imprimiu) {
            std::cout << ", ";
        }
        std::cout << "ACC_SYNTHETIC";
        imprimiu = true;
    }

    if ((flag >> 14) & 0x0001) {
        if (imprimiu) {
            std::cout << ", ";
        }
        std::cout << "ACC_ENUM";
        imprimiu = true;
    }
}

void print_attribute(ClassFile cf, attribute_info attr, int index) {
    info_attribute info;
    u1 info_attribute_type;
    cp_info cp;
    for (u1 i = 0; i < attr.attribute_length; i++) {
        info = attr.info[i];
        info_attribute_type = get_info_attribute_type(
            cf.constant_pool[info.attribute_name_index].info.utf8_info);
        // Index
        std::cout << "{" << std::dec << (u4)i << "} \t";
        // Info
        switch (info_attribute_type) {
            case InfoAttributeType::SourceFile:
                cp = cf.constant_pool[info.info.sourceFile.sourcefile_index];
                std::cout << "SourceFile" << std::endl;
                std::cout << "Generic Info:" << std::endl;
                std::cout << "\tAttribute name index:\t"
                          << "cp_info#" << std::dec << attr.attribute_name_index
                          << std::endl;
                std::cout << "\tAttribute length:\t" << attr.attribute_length
                          << std::endl;
                std::cout << "Specific Info:" << std::endl;
                std::cout << "\tSource File name index: " << std::dec
                          << info.info.sourceFile.sourcefile_index;
                std::cout << "<" << cp.info.utf8_info.bytes << ">" << std::endl;
                break;
            default:
                std::cout << "Not Reconized" << std::endl;
                break;
        }
    }
}
