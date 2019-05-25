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
    std::cout << name << std::endl;

    if (input.is_open()) {
        ClassFile cf = ClassFile();
        read_magic(input, &cf);
        read_minor_version(input, &cf);
        read_major_version(input, &cf);
        read_cpool_count(input, &cf);
        read_constant_pool(input, &cf);
        read_access_flags(input, &cf);
        // read_this_class(input, &cf);
        read_interfaces(input, &cf);
        read_fields(input, &cf);
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
    aux.bytes = (u1 *)malloc(sizeof(u1) * aux.length);
    readf_u1(aux.bytes, file, aux.length);
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
            default:
                exit(1);
        }
    }
}

void Reader::read_access_flags(ifstream &file, ClassFile *cf) {
    readf_u2(&cf->access_flags, file, 1);
}

void Reader::read_this_class(ifstream &file, ClassFile *cf) {
    readf_u2(&cf->this_class, file, 1);
}

void Reader::read_super_class(ifstream &file, ClassFile *cf) {
    file.read((char *)&cf->super_class, sizeof(u2));
    cf->super_class = CorrectEndian::t_u2(cf->super_class);
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
    for (u1 i = 0; i < cf->fields_count - 1; i++) {
        readf_u2(&cf->fields[i].access_flags, file, 1);
        readf_u2(&cf->fields[i].name_index, file, 1);
        readf_u2(&cf->fields[i].descriptor_index, file, 1);
        readf_u2(&cf->fields[i].attributes_count, file, 1);
    }
    // Read attributes
    cf->attributes =
        (attribute_info *)malloc(sizeof(attribute_info) * cf->attributes_count);
    for (u1 i = 0; i < cf->fields_count - 1; i++) {
        for (u1 j = 0; j < cf->attributes_count; i++) {
            readf_u2(&cf->fields[i].attributes[j].attribute_name_index, file,
                     1);
            readf_u4(&cf->fields[i].attributes[j].attribute_length, file, 1);
            cf->fields[i].attributes[j].info =
                (u1 *)malloc(sizeof(u1) * cf->attributes_count);
        }
    }
    // Read info
    // Implementar read_info
}