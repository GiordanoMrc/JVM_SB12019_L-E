#include "exibidor.hpp"

void Printer::showClassFile(ClassFile cf) {
    print_magic(cf);
    print_minor_version(cf);
    print_major_version(cf);
    print_cpool_count(cf);
    // print_constant_pool(cf);
    print_access_flags(cf);
    print_this_class(cf);
    print_super_class(cf);
    print_interfaces_count(cf);
    print_interfaces(cf);
    print_fields_count(cf);
    print_methods_count(cf);
    print_methods(cf);
    print_attributes_count(cf);
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
    if(cf.interfaces_count > 0)
    {
        for(int i = 0; i < cf.interfaces_count; i++)
        {
            std::cout << "Interface " << i << ":"<< std::endl;
            std::cout << cf.interfaces[i] << std::endl;
        }
    }
}

void Printer::print_fields_count(ClassFile cf) {
    std::cout << "Fields: \t";
    std::cout << std::dec << cf.fields_count << std::endl;
}

void Printer::print_fields(ClassFile cf) {}

void Printer::print_methods_count(ClassFile cf) {
    std::cout << "Methods: \t";
    std::cout << std::dec << cf.methods_count << std::endl;
}

void Printer::print_methods(ClassFile cf) 
{
    std::cout<<cf.methods_count<<std::endl;
    if(cf.methods_count > 0)
    {
        for(int i = 0; i < cf.methods_count; i++)
        {
            // struct method_info {
            //     u2 access_flags;
            //     u2 name_index;
            //     u2 descriptor_index;
            //     u2 attributes_count;
            //     attribute_info *attributes;
            // };

            std::cout << "Method " << i << ":"<< std::endl;
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
            case (4):
                memcpy(&aux, &(cp->info.float_info.bytes), sizeof(float));
                std::cout << aux;
                break;
            case (7):
                getIndex_Utf8_Ref(constant_pool, cp->info.class_info.name_index);
                break;
            case (9):
                getIndex_Utf8_Ref(constant_pool, cp->info.fieldref_info.class_index);
                std::cout << ".";
                getIndex_Utf8_Ref(constant_pool, cp->info.fieldref_info.name_and_type_index);
                break;
            case (10):
                getIndex_Utf8_Ref(constant_pool, cp->info.methodref_info.class_index);
                std::cout << ".";
                getIndex_Utf8_Ref(constant_pool, cp->info.methodref_info.name_and_type_index);
                break;
                case(12):
                    getIndex_Utf8_Ref(constant_pool, cp->info.nameandtype_info.name_index);
                    std::cout << ".";
                    getIndex_Utf8_Ref(constant_pool, cp->info.nameandtype_info.descriptor_index);
                    break;
            case (8):
                getIndex_Utf8_Ref(constant_pool, (u2) cp->info.string_info.string_index);
                break;
            case (11):
                getIndex_Utf8_Ref(constant_pool, cp->info.interfacemethodref_info.class_index);
                std::cout << ".";
                getIndex_Utf8_Ref(constant_pool, cp->info.interfacemethodref_info.name_and_type_index);
                break;
            default:
                break;
        }
    }
}

void Printer::print_constant_pool(ClassFile cf){
    printf("--------------------++>>CONSTANT POOL\n");
    u1 tag;
    for (int i = 0; i < cf.cp_count - 1; i++) {
        tag = cf.constant_pool[i].tag;
        switch (tag) {
            case ConstantPoolTags::CONSTANT_Class:
                std::cout << "CONSTANT_Class\t\t" <<"name_index: #"<< cf.constant_pool[i].info.class_info.name_index << "\t\t\t// ";
                getIndex_Utf8_Ref(cf.constant_pool, cf.constant_pool[i].info.class_info.name_index);
                std::cout << std::endl;
                break;
            case ConstantPoolTags::CONSTANT_Fieldref:
                std::cout << "CONSTANT_Fieldref\t" <<"class_index: #"<< cf.constant_pool[i].info.fieldref_info.class_index << "\tname_and_type_index: #"<< cf.constant_pool[i].info.fieldref_info.name_and_type_index<< "// ";
                getIndex_Utf8_Ref(cf.constant_pool, cf.constant_pool[i].info.fieldref_info.class_index);
                getIndex_Utf8_Ref(cf.constant_pool, cf.constant_pool[i].info.fieldref_info.name_and_type_index);
                std::cout << std::endl;
                break;
            case ConstantPoolTags::CONSTANT_Methodref:
                printf("[%d] CONSTANT_Methodref_info\n", i+1);
                printf("\tclass_index: %d ", cf.constant_pool[i].info.methodref_info.class_index);
                getIndex_Utf8_Ref(cf.constant_pool, cf.constant_pool[i].info.methodref_info.class_index);
                std::cout << std::endl;
                printf("\tname_and_type_index: %d ", cf.constant_pool[i].info.methodref_info.name_and_type_index);
                getIndex_Utf8_Ref(cf.constant_pool, cf.constant_pool[i].info.methodref_info.name_and_type_index);
                std::cout << std::endl;
                break;
            case ConstantPoolTags::CONSTANT_InterfaceMethodref:
                printf("[%d] CONSTANT_InterfaceMethodref_info\n", i+1);
                printf("\tclass_index: %d ", cf.constant_pool[i].info.interfacemethodref_info.class_index);
                getIndex_Utf8_Ref(cf.constant_pool, cf.constant_pool[i].info.interfacemethodref_info.class_index);
                std::cout << std::endl;
                printf("\tname_and_type_index: %d ", cf.constant_pool[i].info.interfacemethodref_info.name_and_type_index);
                getIndex_Utf8_Ref(cf.constant_pool, cf.constant_pool[i].info.interfacemethodref_info.name_and_type_index);
                std::cout << std::endl;
                break;
            case ConstantPoolTags::CONSTANT_String:
                printf("%dCONSTANT_String_info\n", i+1);
                printf("\tstring_index: %d ", cf.constant_pool[i].info.string_info.string_index);
                getIndex_Utf8_Ref(cf.constant_pool, cf.constant_pool[i].info.string_info.string_index);
                std::cout << std::endl;
                break;
            /*case ConstantPoolTags::CONSTANT_Integer:
                printf("[%d] CONSTANT_Integer_info\n", i+1);
                printf("\tbytes: %d", (int32_t)cf.constant_pool[i].info.string_info.bytes);
                break;
            case ConstantPoolTags::CONSTANT_Float:
                printf("[%d] CONSTANT_Float_info\n", i+1);
                printf("\tbytes: 0x%08x\n", cf.constant_pool[i].info.float_info.bytes);
                printf("\tfloat: %.2f", *(float *)&cf.constant_pool[i].info.float_info.bytes);
                break;
            case ConstantPoolTags::CONSTANT_Long:
                printf("[%d] CONSTANT_Long_info\n", i+1);
                printf("\thigh_bytes: %u\n", cf.constant_pool[i].info.long_value.high_bytes);
                printf("\tlow_bytes: %u\n", cf.constant_pool[i].info.long_value.low_bytes);
                u8 long = ((u8)cf.constant_pool[i].info.long_value.high_bytes << 32) | cf.constant_pool[i].info.long_value.low_bytes;
                printf("\nlong: %ld", (long)long_value);
                break;
            case ConstantPoolTags::CONSTANT_Double:
                printf("[%d] CONSTANT_Double_info\n", i+1);
                printf("\thigh_bytes: %u\n", cf.constant_pool[i].info.double_value.high_bytes);
                printf("\tlow_bytes: %u\n", cf.constant_pool[i].info.double_value.low_bytes);
                u8 double_value = ((u8)cf.constant_pool[i].info.double_value.high_bytes << 32) | cf.constant_pool[i].info.double_value.low_bytes;
                printf("\ndouble: %.2f", *(double *)&double_value);
                break;*/
            default:
                break;
        }
        std::cout << std::endl;
    }
}
