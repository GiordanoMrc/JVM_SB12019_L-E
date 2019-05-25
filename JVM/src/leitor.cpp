#include "leitor.hpp"

long int getSizeofConstant(int tag);

#define readFile(type , tam)\

u1 readf_u1(u1* pointer,ifstream &file, int n_count){
    file.read((char*)pointer,n_count);
    return *pointer;
}

#define readf_(type, tam)                                           \
    type readf_##type(type* pointer,ifstream &file, int n_count){    \
        type aux;                                                   \
        for(int i=0; i<n_count; i++){                               \
            file.read((char*)&aux, tam);                            \
            aux = CorrectEndian::t_##type(aux);                     \
            *(pointer+i) = aux;                                     \
        }                                                           \
        return (aux);                                               \
    }
readf_(u2,2);
readf_(u4,4);
readf_(u8,8);

ClassFile Reader::getClassFile(std::string name) {
    ifstream input(name, ios::binary);
    std::cout << name << std::endl;

    if (input.is_open()) {
        ClassFile cf = ClassFile();
        read_magic(input, &cf);
        read_minor_version(input, &cf);
        read_major_version(input, &cf);
        read_cpool_count(input, &cf);
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
    file.read((char *)&cf->minor_version, sizeof(u2));
    cf->minor_version = CorrectEndian::t_u2(cf->minor_version);
}
void Reader::read_major_version(ifstream &file, ClassFile *cf) {
    file.read((char *)&cf->major_version, sizeof(u2));
    cf->major_version = CorrectEndian::t_u2(cf->major_version);
}

void Reader::read_cpool_count(ifstream &file, ClassFile *cf) {
    file.read((char *)&cf->cp_count, sizeof(u2));
    cf->cp_count = CorrectEndian::t_u2(cf->cp_count);
}
void Reader::read_constant_pool(ifstream &file, ClassFile *cf) {
  u2  cp_size = cf->cp_count -1;
  cf->constant_pool = (cp_info*) malloc (sizeof(cp_info) * cp_size);

  for(u2 i=0; i < cp_size; i++){
      readf_u1(&cf->constant_pool[i].tag,file,1);
      //std::cout << tag;

      switch (cf->constant_pool[i].tag){
          case CONSTANT_Class:
              CONSTANT_Class_info aux;
              cf->constant_pool[i].info.class_info = readf_u2(&aux.name_index,file,1);
              break;
          /*case CONSTANT_Fieldref:
              constant_pool[i].info.fieldref_info = getConstantClassInfo();
              break;
          case CONSTANT_Methodref:
              constant_pool[i].info.class_methodref_info = getConstantClassInfo();
              break;
          case CONSTANT_String:
              constant_pool[i].info.class_string_info = getConstantClassInfo();
              break;
          case CONSTANT_Utf8:
              constant_pool[i].info.class_uft8_info = getConstantClassInfo();
              break;
          case CONSTANT_NameAndType:
              constant_pool[i].info.class_nameAndType_info = getConstantClassInfo();
              break;
          case CONSTANT_InterfaceMethodref:
              //constant_pool[i].info.class_info = getConstantClassInfo();
              break;
          case CONSTANT_Integer:
              //constant_pool[i].info.class_info = getConstantClassInfo();
              break;
          case CONSTANT_Float:
              //constant_pool[i].info.class_info = getConstantClassInfo();
              break;
          case CONSTANT_Long:
              //constant_pool[i].info.class_info = getConstantClassInfo();
              break;
          case CONSTANT_Long:
              //constant_pool[i].info.class_info = getConstantClassInfo();
              break;
          case CONSTANT_Long:
              //constant_pool[i].info.class_info = getConstantClassInfo();
              break;
          case CONSTANT_Long:
              //constant_pool[i].info.class_info = getConstantClassInfo();
              break;
          case CONSTANT_Long:
              //constant_pool[i].info.class_info = getConstantClassInfo();
              break;
              case CONSTANT_Long:
              //constant_pool[i].info.class_info = getConstantClassInfo();
              break;
          case CONSTANT_Long:
              //constant_pool[i].info.class_info = getConstantClassInfo();
              break;*/
          default:
              exit(1);
      }

  }
}


void Reader::read_access_flags(ifstream &file, ClassFile *cf) {
    file.read((char *)&cf->access_flags, sizeof(u2));
    cf->access_flags = CorrectEndian::t_u2(cf->access_flags);
}

void Reader::read_this_class(ifstream &file, ClassFile *cf) {
    file.read((char *)&cf->this_class, sizeof(u2));
    cf->this_class = CorrectEndian::t_u2(cf->this_class);
}

void Reader::read_super_class(ifstream &file, ClassFile *cf) {
    file.read((char *)&cf->super_class, sizeof(u2));
    cf->super_class = CorrectEndian::t_u2(cf->super_class);
}

long int getSizeofConstant(int tag) {
    switch (tag) {
        case CONSTANT_Methodref:
            return sizeof(CONSTANT_Methodref_info);
            break;
        default:
            exit(EXIT_FAILURE);
            break;
    }
}