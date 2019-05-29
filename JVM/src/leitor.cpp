#include "leitor.hpp"

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
        input.close();
        return cf;
    } else {
        std::cout << "Não foi possível abrir o arquivo" << std::endl;
        exit(EXIT_FAILURE);
    }
}

void Reader::read_magic(ifstream &file, ClassFile *cf) {
    readt_u4(&cf->magic, file, 1);
}

void Reader::read_minor_version(ifstream &file, ClassFile *cf) {
    readt_u2(&cf->minor_version, file, 1);
}
void Reader::read_major_version(ifstream &file, ClassFile *cf) {
    readt_u2(&cf->major_version, file, 1);
}
void Reader::read_cpool_count(ifstream &file, ClassFile *cf) {
    readt_u2(&cf->cp_count, file, 1);
}
void Reader::read_constant_pool(ifstream &file, ClassFile *cf) {
    u2 cp_size = cf->cp_count - 1;
    cf->constant_pool = (cp_info *)malloc(sizeof(cp_info) * cp_size);
    for (u2 i = 0; i < cp_size; i++) {
        // Read tag
        readt_u1(&cf->constant_pool[i].tag, file, 1);
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
                break;
            case ConstantPoolTags::CONSTANT_String:
                break;
            case ConstantPoolTags::CONSTANT_Integer:
                break;
            case ConstantPoolTags::CONSTANT_Float:
                break;
            case ConstantPoolTags::CONSTANT_Long:
                // After CONSTANT_Long next usable item in the pool is located
                // at index n+2 read constant i
                i++;
                // constant position i + 1
                break;
            case ConstantPoolTags::CONSTANT_Double:
                // After CONSTANT_Double next usable item in the pool is located
                // at index n+2 read constant i
                i++;
                // constant position i + 1
                break;
            case ConstantPoolTags::CONSTANT_MethodHandle:
                break;
            case ConstantPoolTags::CONSTANT_MethodType:
                break;
            case ConstantPoolTags::CONSTANT_InvokeDynamic:
                break;
            default:
                cout << "Not reconized" << endl;
                cout << "tag = " << dec << cf->constant_pool[i].tag << endl;
                exit(100);
                break;
        }
    }
}

void Reader::read_access_flags(ifstream &file, ClassFile *cf) {
    readt_u2(&cf->access_flags, file, 1);
}
