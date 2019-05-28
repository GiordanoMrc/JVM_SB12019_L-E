#include "leitor.hpp"

u1 readf_u1(u1 *pointer, ifstream &file, int n_count) {
    file.read((char *)pointer, n_count);
    return *pointer;
}

#define readf_(type, tam)                                           \
    type readf_##type(type *pointer, ifstream &file, int n_count) { \
        type aux;                                                   \
        for (int i = 0; i < n_count; i++) {                         \
            file.read((char *)&aux, tam);                           \
            aux = CorrectEndian::t_##type(aux);                     \
            *(pointer + i) = aux;                                   \
        }                                                           \
        return (aux);                                               \
    }
readf_(u2, 2);
readf_(u4, 4);
readf_(u8, 8);

ClassFile Reader::getClassFile(std::string name) {
    ifstream input(name, ios::binary);
    std::cout << "Nome do Arquivo:" << name << std::endl;

    if (input.is_open()) {
        ClassFile cf = ClassFile();
        read_magic(input, &cf);
        read_minor_version(input, &cf);
        read_major_version(input, &cf);
        read_cpool_count(input, &cf);
        read_constant_pool(input, &cf);
        read_access_flags(input, &cf);
        read_this_class(input, &cf);
        read_super_class(input, &cf);
        read_interfaces(input, &cf);
        read_fields(input, &cf);
        read_methods(input, &cf);
        read_attributes(input, &cf);
        input.close();
        return cf;
    } else {
        std::cout << "Não foi possível abrir o arquivo" << std::endl;
        exit(EXIT_FAILURE);
    }
}

void Reader::read_magic(ifstream &file, ClassFile *cf) {
    readf_u4(&cf->magic, file, 1);
}

void Reader::read_minor_version(ifstream &file, ClassFile *cf) {
    readf_u2(&cf->minor_version, file, 1);
}
void Reader::read_major_version(ifstream &file, ClassFile *cf) {
    readf_u2(&cf->major_version, file, 1);
}

void Reader::read_cpool_count(ifstream &file, ClassFile *cf) {
    readf_u2(&cf->cp_count, file, 1);
}

CONSTANT_Class_info getConstantClassInfo(ifstream &file) {
    CONSTANT_Class_info aux;
    readf_u2(&aux.name_index, file, 1);
    return aux;
}

CONSTANT_Fieldref_info getConstantFieldRef(ifstream &file) {
    CONSTANT_Fieldref_info aux;
    readf_u2(&aux.class_index, file, 1);
    readf_u2(&aux.name_and_type_index, file, 1);
    return aux;
}

CONSTANT_NameAndType_info getConstantNameAndTypeInfo(ifstream &file) {
    CONSTANT_NameAndType_info aux;
    readf_u2(&aux.name_index, file, 1);
    readf_u2(&aux.descriptor_index, file, 1);
    return aux;
}

CONSTANT_Utf8_info getConstantUtf8Info(ifstream &file) {
    CONSTANT_Utf8_info aux;
    readf_u2(&aux.length, file, 1);
    aux.bytes = (u1 *)malloc(sizeof(u1) * aux.length + 1);
    readf_u1(aux.bytes, file, aux.length);
    aux.bytes[aux.length] = '\0';
    return aux;
}

CONSTANT_Methodref_info getConstantMethodRefInfo(ifstream &file) {
    CONSTANT_Methodref_info aux;
    readf_u2(&aux.class_index, file, 1);
    readf_u2(&aux.name_and_type_index, file, 1);
    return aux;
}

CONSTANT_InterfaceMethodref_info getConstantInterfaceMethodRefInfo(
    ifstream &file) {
    CONSTANT_InterfaceMethodref_info aux;
    readf_u2(&aux.class_index, file, 1);
    readf_u2(&aux.name_and_type_index, file, 1);
    return aux;
}

CONSTANT_String_info getConstantStringInfo(ifstream &file) {
    CONSTANT_String_info aux;
    readf_u2(&aux.string_index, file, 1);
    return aux;
}

CONSTANT_Integer_info getConstantIntegerInfo(ifstream &file) {
    CONSTANT_Integer_info aux;
    readf_u4(&aux.bytes, file, 1);
    return aux;
}

CONSTANT_Float_info getConstantFloatInfo(ifstream &file) {
    CONSTANT_Float_info aux;
    readf_u4(&aux.bytes, file, 1);
    return aux;
}

CONSTANT_Long_info getConstantLongInfo(ifstream &file) {
    CONSTANT_Long_info aux;
    readf_u4(&aux.high_bytes, file, 1);
    readf_u4(&aux.low_bytes, file, 1);
    return aux;
}

CONSTANT_Double_info getConstantDoubleInfo(ifstream &file) {
    CONSTANT_Double_info aux;
    readf_u4(&aux.high_bytes, file, 1);
    readf_u4(&aux.low_bytes, file, 1);
    return aux;
}

CONSTANT_MethodHandle_info getConstantMethodHandleInfo(ifstream &file) {
    CONSTANT_MethodHandle_info aux;
    readf_u1(&aux.reference_kind, file, 1);
    readf_u2(&aux.reference_index, file, 1);
    return aux;
}

CONSTANT_MethodType_info getConstantMethodTypeInfo(ifstream &file) {
    CONSTANT_MethodType_info aux;

    readf_u2(&aux.descriptor_index, file, 1);
    return aux;
}

CONSTANT_InvokeDynamic_info getConstantInvokeDynamicInfo(ifstream &file) {
    CONSTANT_InvokeDynamic_info aux;

    readf_u2(&aux.bootstrap_method_attr_index, file, 1);
    readf_u2(&aux.name_and_type_index, file, 1);

    return aux;
}

void Reader::read_constant_pool(ifstream &file, ClassFile *cf) {
    u2 cp_size = cf->cp_count - 1;
    cf->constant_pool = (cp_info *)malloc(sizeof(cp_info) * cp_size);
    for (u2 i = 0; i < cp_size; i++) {
        // Read tag
        readf_u1(&cf->constant_pool[i].tag, file, 1);
        // Read info
        switch (cf->constant_pool[i].tag) {
            case ConstantPoolTags::CONSTANT_Class:
                cf->constant_pool[i].info.class_info =
                    getConstantClassInfo(file);
                break;
            case ConstantPoolTags::CONSTANT_Fieldref:
                cf->constant_pool[i].info.fieldref_info =
                    getConstantFieldRef(file);
                break;
            case ConstantPoolTags::CONSTANT_NameAndType:
                cf->constant_pool[i].info.nameandtype_info =
                    getConstantNameAndTypeInfo(file);
                break;
            case ConstantPoolTags::CONSTANT_Utf8:
                cf->constant_pool[i].info.utf8_info = getConstantUtf8Info(file);
                break;
            case ConstantPoolTags::CONSTANT_Methodref:
                cf->constant_pool[i].info.methodref_info =
                    getConstantMethodRefInfo(file);
                break;
            case ConstantPoolTags::CONSTANT_InterfaceMethodref:
                cf->constant_pool[i].info.interfacemethodref_info =
                    getConstantInterfaceMethodRefInfo(file);
                break;
            case ConstantPoolTags::CONSTANT_String:
                cf->constant_pool[i].info.string_info =
                    getConstantStringInfo(file);
                break;
            case ConstantPoolTags::CONSTANT_Integer:
                cf->constant_pool[i].info.integer_info =
                    getConstantIntegerInfo(file);
                break;
            case ConstantPoolTags::CONSTANT_Float:
                cf->constant_pool[i].info.float_info =
                    getConstantFloatInfo(file);
                break;
            case ConstantPoolTags::CONSTANT_Long:
                cf->constant_pool[i].info.long_info = getConstantLongInfo(file);
                break;
            case ConstantPoolTags::CONSTANT_Double:
                cf->constant_pool[i].info.double_info =
                    getConstantDoubleInfo(file);
                break;
            case ConstantPoolTags::CONSTANT_MethodHandle:
                cf->constant_pool[i].info.methodhandle_info =
                    getConstantMethodHandleInfo(file);
                break;
            case ConstantPoolTags::CONSTANT_MethodType:
                cf->constant_pool[i].info.methodtype_info =
                    getConstantMethodTypeInfo(file);
                break;
            case ConstantPoolTags::CONSTANT_InvokeDynamic:
                cf->constant_pool[i].info.invokedynamic_info =
                    getConstantInvokeDynamicInfo(file);
                break;
            default:
                exit(100);
        }
    }
}

void Reader::read_this_class(ifstream &file, ClassFile *cf) {
    readf_u2(&cf->this_class, file, 1);
}

void Reader::read_super_class(ifstream &file, ClassFile *cf) {
    readf_u2(&cf->super_class, file, 1);
}

void Reader::read_access_flags(ifstream &file, ClassFile *cf) {
    readf_u2(&cf->access_flags, file, 1);
}

void Reader::read_interfaces(ifstream &file, ClassFile *cf) {
    readf_u2(&cf->interfaces_count, file, 1);
    cf->interfaces = (u2 *)malloc(sizeof(u2) * cf->interfaces_count);
    readf_u2(cf->interfaces, file, cf->interfaces_count);
}

void Reader::read_fields(ifstream &file, ClassFile *cf) {
    readf_u2(&cf->fields_count, file, 1);
    // Read Fields
    cf->fields = (field_info *)malloc(sizeof(field_info) * cf->fields_count);
    for (u1 i = 0; i < cf->fields_count; i++) {
        read_field(file, &cf->fields[i]);
    }
}

void read_field(ifstream &file, field_info *field) {
    readf_u2(&field->access_flags, file, 1);
    readf_u2(&field->name_index, file, 1);
    readf_u2(&field->descriptor_index, file, 1);
    readf_u2(&field->attributes_count, file, 1);
    field->attributes = (attribute_info *)malloc(sizeof(attribute_info) *
                                                 field->attributes_count);
    for (u1 j = 0; j < field->attributes_count; j++) {
        read_attribute(file, &field->attributes[j]);
    }
}

void Reader::read_methods(ifstream &file, ClassFile *cf) {
    readf_u2(&cf->methods_count, file, 1);
    // Read methods
    cf->methods =
        (method_info *)malloc(sizeof(method_info) * cf->methods_count);
    for (u1 i = 0; i < cf->methods_count; i++) {
        readf_u2(&cf->methods[i].access_flags, file, 1);
        readf_u2(&cf->methods[i].name_index, file, 1);
        readf_u2(&cf->methods[i].descriptor_index, file, 1);
        readf_u2(&cf->methods[i].attributes_count, file, 1);
        cf->methods[i].attributes = (attribute_info *)malloc(
            sizeof(attribute_info) * cf->methods[i].attributes_count);
        for (u1 j = 0; j < cf->methods[i].attributes_count; j++) {
            read_attribute(file, &cf->methods[i].attributes[j]);
        }
    }
}

void read_attribute(ifstream &file, attribute_info *attribute) {
    readf_u2(&attribute->attribute_name_index, file, 1);
    readf_u4(&attribute->attribute_length, file, 1);
    attribute->info = (info_attribute *)malloc(sizeof(info_attribute) *
                                               attribute->attribute_length);
    for (u1 k = 0; k < attribute->attribute_length; k++) {
        readf_u1((u1 *)&attribute->info[k], file, 1);
    }
}
void Reader::read_attributes(ifstream &file, ClassFile *cf) {
    readf_u2(&cf->attributes_count, file, 1);
    // Read attributes
    cf->attributes =
        (attribute_info *)malloc(sizeof(attribute_info) * cf->attributes_count);
    for (u1 i = 0; i < cf->attributes_count; i++) {
        read_attribute(file, &cf->attributes[i]);
    }
}

int comparaIgual(CONSTANT_Utf8_info utf8_struct, std::string nomeAttributo) {
    if (utf8_struct.length != nomeAttributo.size()) {
        return false;
    }
    for (u2 i = 0; i < utf8_struct.length; i++) {
        if (utf8_struct.bytes[i] != nomeAttributo[i]) {
            return false;
        }
    }
    return true;
}
