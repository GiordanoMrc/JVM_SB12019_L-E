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
    print_fields(cf);


    // print_methods(cf);
    // print_attributes(cf);
}

void get_Access_Flag_Field1(u2 flag){

    if(flag&1){
        std::cout << "public ";
    }

    if((flag>>1)&0x0001){
        std::cout << "private ";
    }

    if((flag>>2)&0x0001){
        std::cout << "protected ";
    }

    if((flag>>3)&0x0001){
        std::cout << "static ";
    }

    if((flag>>4)&0x0001){
        std::cout << "final ";
    }

    if((flag>>6)&0x0001){
        std::cout << "volatile ";
    }

    if((flag>>7)&0x0001){
        std::cout << "transient ";
    }

    if((flag>>13)&0x0001){
        std::cout << "synthetic ";
    }

    if((flag>>14)&0x0001){
        std::cout << "enum ";
    }
}

void get_Access_Flag_Field2(u2 flag){
    bool imprimiu = false;


    if(flag&1){
        std::cout << "ACC_PUBLIC";
        imprimiu = true;
    }

    if((flag>>1)&0x0001){
        if(imprimiu){
            std::cout << ", ";
        }
        std::cout << "ACC_PRIVATE";
        imprimiu = true;
    }

    if((flag>>2)&0x0001){
        if(imprimiu){
            std::cout << ", ";
        }
        std::cout << "ACC_PROTECTED";
        imprimiu = true;
    }

    if((flag>>3)&0x0001){
        if(imprimiu){
            std::cout << ", ";
        }
        std::cout << "ACC_STATIC";
        imprimiu = true;
    }

    if((flag>>4)&0x0001){
        if(imprimiu){
            std::cout << ", ";
        }
        std::cout << "ACC_FINAL";
        imprimiu = true;
    }

    if((flag>>6)&0x0001){
        if(imprimiu){
            std::cout << ", ";
        }
        std::cout << "ACC_VOLATILE";
        imprimiu = true;
    }

    if((flag>>7)&0x0001){
        if(imprimiu){
            std::cout << ", ";
        }
        std::cout << "ACC_TRANSIENT";
        imprimiu = true;
    }

    if((flag>>13)&0x0001){
        if(imprimiu){
            std::cout << ", ";
        }
        std::cout << "ACC_SYNTHETIC";
        imprimiu = true;
    }

    if((flag>>14)&0x0001){
        if(imprimiu){
            std::cout << ", ";
        }
        std::cout << "ACC_ENUM";
        imprimiu = true;
    }
}

void Printer::print_fields(ClassFile cf){
    printf("\n--------------------++>>Fields\n");
    for(int i=0; i<cf.fields_count; i++){
        field_info field = (cf.fields[i]);

        get_Access_Flag_Field1(field.access_flags);
        getIndex_Utf8_Ref(cf.constant_pool, field.name_index);
        std::cout << std::endl;

        std::cout << "     descriptor: ";

        getIndex_Utf8_Ref(cf.constant_pool, field.descriptor_index);
        std::cout << std::endl;


        std::cout << "     flags: ";

        get_Access_Flag_Field2(field.access_flags);
        std::cout << std::endl;


        for (int i = 0; i < field.attributes_count; i++) {
            std::cout << "Attribute " << i+1 << std::endl;

			//print_attributes(field.attributes + i, cf.constant_pool);
		}
		std::cout << std::endl;

    }
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
        cf.constant_pool[cp_info_index].info.class_info.name_index - 1;
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
        printf("\n--------------------++>>Interfaces:\n");
        for (int i = 0; i < cf.interfaces_count; i++) {
            std::cout << "Interface " << i << ":" << std::endl;
            std::cout << cf.interfaces[i] << std::endl;
            getIndex_Utf8_Ref(cf.constant_pool, *(cf.interfaces+i));
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
/*void Screen_Print_Access_Flag_Method1(u2 flag){
    bool imprimiu = false;


    if(flag&1){
        std::cout << "ACC_PUBLIC";
        imprimiu = true;
    }

    if((flag>>1)&0x0001){
        if(imprimiu){
            std::cout << ", ";
        }
        std::cout << "ACC_PRIVATE";
        imprimiu = true;
    }

    if((flag>>2)&0x0001){
        if(imprimiu){
            std::cout << ", ";
        }
        std::cout << "ACC_PROTECTED";
        imprimiu = true;
    }

    if((flag>>3)&0x0001){
        if(imprimiu){
            std::cout << ", ";
        }
        std::cout << "ACC_STATIC";
        imprimiu = true;
    }

    if((flag>>4)&0x0001){
        if(imprimiu){
            std::cout << ", ";
        }
        std::cout << "ACC_FINAL";
        imprimiu = true;
    }

    if((flag>>5)&0x0001){
        if(imprimiu){
            std::cout << ", ";
        }
        std::cout << "ACC_SYNCHRONIZED";
        imprimiu = true;
    }

    if((flag>>6)&0x0001){
        if(imprimiu){
            std::cout << ", ";
        }
        std::cout << "ACC_BRIDGE";
        imprimiu = true;
    }

    if((flag>>7)&0x0001){
        if(imprimiu){
            std::cout << ", ";
        }
        std::cout << "ACC_VARARGS";
        imprimiu = true;
    }

    if((flag>>8)&0x0001){
        if(imprimiu){
            std::cout << ", ";
        }
        std::cout << "ACC_NATIVE";
        imprimiu = true;
    }

    if((flag>>9)&0x0001){
        if(imprimiu){
            std::cout << ", ";
        }
        std::cout << "ACC_ABSTRACT";
        imprimiu = true;
    }

    if((flag>>10)&0x0001){
        if(imprimiu){
            std::cout << ", ";
        }
        std::cout << "ACC_STRICT";
        imprimiu = true;
    }

    if((flag>>11)&0x0001){
        if(imprimiu){
            std::cout << ", ";
        }
        std::cout << "ACC_SYNTHETIC";
        imprimiu = true;
    }
}

void Screen_Print_Access_Flag_Method2(u2 flag){

    if(flag&1){
        std::cout << "public ";
    }

    if((flag>>1)&0x0001){
        std::cout << "private ";
    }

    if((flag>>2)&0x0001){
        std::cout << "protected ";
    }

    if((flag>>3)&0x0001){
        std::cout << "static ";
    }

    if((flag>>4)&0x0001){
        std::cout << "final ";
    }

    if((flag>>5)&0x0001){
        std::cout << "synchronized ";
    }

    if((flag>>6)&0x0001){
        std::cout << "bridge ";
    }

    if((flag>>7)&0x0001){
        std::cout << "varargs ";
    }

    if((flag>>8)&0x0001){
        std::cout << "native ";
    }

    if((flag>>9)&0x0001){
        std::cout << "abstract ";
    }

    if((flag>>10)&0x0001){
        std::cout << "strict ";
    }

    if((flag>>11)&0x0001){
        std::cout << "synthetic ";
    }
}


void Printer::print_methods(ClassFile cf)
{
        //Loop para printar os m�todos
    for(u2 i = 0; i < cf.methods_count; i++)
    {
        method_info method = (cf.methods[i]);

        getIndex_Utf8_Ref(cf.constant_pool, method.name_index);
        std::cout << std::endl;

        std::cout << "     descriptor: ";

        getIndex_Utf8_Ref(cf.constant_pool, method.descriptor_index);
        std::cout << std::endl;


        std::cout << "     flags: ";

        // Screen_Print_Access_Flag_Method1(method.access_flags);
        std::cout << std::endl;


                for (int i = 0; i < method.attributes_count; i++) {
                        //print_attibutes(method.attributes + i,
cf.constant_pool);
                }
    }
}
*/
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
                                  (u2)cp->info.string_info.string_index);
                break;
            case (ConstantPoolTags::CONSTANT_InterfaceMethodref):
                getIndex_Utf8_Ref(constant_pool,
                                  cp->info.interfacemethodref_info.class_index);
                std::cout << ".";
                getIndex_Utf8_Ref(
                    constant_pool,
                    cp->info.interfacemethodref_info.name_and_type_index);
                break;
            case (ConstantPoolTags::CONSTANT_MethodHandle):
                getIndex_Utf8_Ref(constant_pool,
                                  cp->info.methodhandle_info.reference_index);
                break;
            case (ConstantPoolTags::CONSTANT_MethodType):
                getIndex_Utf8_Ref(constant_pool,
                                  cp->info.methodtype_info.descriptor_index);
                break;
            case (ConstantPoolTags::CONSTANT_InvokeDynamic):
                getIndex_Utf8_Ref(
                    constant_pool,
                    cp->info.invokedynamic_info.bootstrap_method_attr_index);
                getIndex_Utf8_Ref(
                    constant_pool,
                    cp->info.invokedynamic_info.name_and_type_index);
                break;
            default:
                break;
        }
    }
}

void Printer::print_constant_pool(ClassFile cf) {
    printf("\n--------------------++>>CONSTANT POOL\n");
    u1 tag;
    u8 long_v, double_v;
    for (int i = 0; i < cf.cp_count - 1; i++) {
        tag = cf.constant_pool[i].tag;
        switch (tag) {
            case ConstantPoolTags::CONSTANT_Class:
                std::cout << "{" << i + 1 << "}"
                          << "CONSTANT_Class\t"
                          << "name_index: #"
                          << cf.constant_pool[i].info.class_info.name_index
                          << " \t//";
                getIndex_Utf8_Ref(
                    cf.constant_pool,
                    cf.constant_pool[i].info.class_info.name_index);
                break;
            case ConstantPoolTags::CONSTANT_Fieldref:
                std::cout << "{" << i + 1 << "}"
                          << "CONSTANT_Fieldref\t"
                          << "class_index: #"
                          << cf.constant_pool[i].info.fieldref_info.class_index
                          << "\tname_and_type_index: #"
                          << cf.constant_pool[i]
                                 .info.fieldref_info.name_and_type_index
                          << " \t//";
                getIndex_Utf8_Ref(
                    cf.constant_pool,
                    cf.constant_pool[i].info.fieldref_info.class_index);
                getIndex_Utf8_Ref(
                    cf.constant_pool,
                    cf.constant_pool[i].info.fieldref_info.name_and_type_index);
                break;
            case ConstantPoolTags::CONSTANT_Methodref:
                std::cout << "{" << i + 1 << "}"
                          << "CONSTANT_Methodref_info\t"
                          << "class_index: #"
                          << cf.constant_pool[i].info.methodref_info.class_index
                          << "\tname_and_type_index: #"
                          << cf.constant_pool[i]
                                 .info.methodref_info.name_and_type_index
                          << " \t//";
                getIndex_Utf8_Ref(
                    cf.constant_pool,
                    cf.constant_pool[i].info.methodref_info.class_index);
                getIndex_Utf8_Ref(cf.constant_pool,
                                  cf.constant_pool[i]
                                      .info.methodref_info.name_and_type_index);
                break;
            case ConstantPoolTags::CONSTANT_InterfaceMethodref:
                std::cout
                    << "{" << i + 1 << "}"
                    << "CONSTANT_InterfaceMethodref_info\t"
                    << "class_index: #"
                    << cf.constant_pool[i]
                           .info.interfacemethodref_info.class_index
                    << "\tname_and_type_index: #"
                    << cf.constant_pool[i]
                           .info.interfacemethodref_info.name_and_type_index
                    << " \t//";
                getIndex_Utf8_Ref(
                    cf.constant_pool,
                    cf.constant_pool[i]
                        .info.interfacemethodref_info.class_index);
                getIndex_Utf8_Ref(
                    cf.constant_pool,
                    cf.constant_pool[i]
                        .info.interfacemethodref_info.name_and_type_index);
                break;

            case ConstantPoolTags::CONSTANT_String:
                std::cout << "{" << i + 1 << "}"
                          << "CONSTANT_String_info\t"
                          << "string_index: #"
                          << cf.constant_pool[i].info.string_info.string_index
                          << " \t//";
                getIndex_Utf8_Ref(
                    cf.constant_pool,
                    cf.constant_pool[i].info.string_info.string_index);
                break;
            case ConstantPoolTags::CONSTANT_Integer:
                std::cout << "{" << i + 1 << "}"
                          << "CONSTANT_Integer_info\t"
                          << "bytes: "
                          << (u4)cf.constant_pool[i].info.integer_info.bytes;
                break;
            case ConstantPoolTags::CONSTANT_Float:
                std::cout << "{" << i + 1 << "}"
                          << "CONSTANT_Float:\t";
                printf("\tbytes: 0x%08x",
                       cf.constant_pool[i].info.float_info.bytes);
                printf("\tfloat: %.2f",
                       *(float *)&cf.constant_pool[i].info.float_info.bytes);
                break;

            case ConstantPoolTags::CONSTANT_Long:
                std::cout << "{" << i + 1 << "}"
                          << "CONSTANT_Long:\t";
                printf("\thigh_bytes: %u",
                       cf.constant_pool[i].info.long_info.high_bytes);
                printf("\tlow_bytes: %u",
                       cf.constant_pool[i].info.long_info.low_bytes);
                long_v =
                    ((u8)cf.constant_pool[i].info.long_info.high_bytes << 32) |
                    cf.constant_pool[i].info.long_info.low_bytes;
                printf("long: %ld", (long)long_v);
                break;

            case ConstantPoolTags::CONSTANT_Double:
                std::cout << "{" << i + 1 << "}"
                          << "CONSTANT_Double:\t";
                printf("\thigh_bytes: %u",
                       cf.constant_pool[i].info.double_info.high_bytes);
                printf("\tlow_bytes: %u",
                       cf.constant_pool[i].info.double_info.low_bytes);
                double_v = ((u8)cf.constant_pool[i].info.double_info.high_bytes
                            << 32) |
                           cf.constant_pool[i].info.double_info.low_bytes;
                printf("double: %.2f", *(double *)&double_v);

                break;

            case ConstantPoolTags::CONSTANT_NameAndType:
                std::cout
                    << "{" << i + 1 << "}"
                    << "CONSTANT_NameAndType\t"
                    << "name_index: "
                    << cf.constant_pool[i].info.nameandtype_info.name_index
                    << "\tdescriptor_index:"
                    << cf.constant_pool[i]
                           .info.nameandtype_info.descriptor_index
                    << " \t//";
                getIndex_Utf8_Ref(
                    cf.constant_pool,
                    cf.constant_pool[i].info.nameandtype_info.name_index);
                getIndex_Utf8_Ref(
                    cf.constant_pool,
                    cf.constant_pool[i].info.nameandtype_info.descriptor_index);
                break;
            case ConstantPoolTags::CONSTANT_Utf8:
                std::cout << "{" << i + 1 << "}"
                          << "CONSTANT_Utf8\t"
                          << cf.constant_pool[i].info.utf8_info.bytes;
                break;
            default:
                break;
        }
        std::cout << std::endl;
    }
    printf("\n--------------------++>>CONSTANT POOL\n");
}
/*
void Printer::print_attributes(ClassFile cf) {
    std::cout << "########################\n### Class Attributes "
                 "###\n########################"
              << std::endl;
    std::cout << "Count: " << std::dec << cf.attributes_count << std::endl
              << std::endl;
    for (int i = 0; i < cf.attributes_count; i++) {
        print_attribute(cf, cf.attributes[i], i);
    }
}

int get_info_attribute_type(CONSTANT_Utf8_info info) {
    string name = string((char *)info.bytes);
    if (name == "SourceFile") {
        return InfoAttributeType::SourceFile;
    };
    return InfoAttributeType::NotReconized;
}

void print_attribute(ClassFile cf, attribute_info attr, int index) {
    attribute_info info;
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
                cp = cf.constant_pool[info.sourceFile_attribute
                                          .sourcefile_index];
                std::cout << "SourceFile" << endl;
                std::cout << "Generic Info:" << endl;
                std::cout << "\tAttribute name index:\t"
                          << "cp_info#" << std::dec << attr.attribute_name_index
                          << endl;
                std::cout << "\tAttribute length:\t" << attr.attribute_length
                          << endl;
                std::cout << "Specific Info:" << endl;
                std::cout << "\tSource File name index: " << std::dec
                          << info.sourceFile_attribute.sourcefile_index;
                std::cout << "<" << cp.info.utf8_info.bytes << ">" << endl;
                break;
            default:
                cout << "Not Reconized" << endl;
                break;
        }
    }
}*/

void print_attibutes(attribute_info* ai, cp_info* cp) {
        char type[100];
        strcpy(type, (char*)cp[ai->attribute_name_index -1].info.utf8_info.bytes);
        std::cout << type << ":\t//Attribute length: " << ai->attribute_length << std::endl;

//#define printype(name,function) if(strcmp(name,type)==0) { function; }
//	screen_print_functionS(printype)
//#undef printype
}
