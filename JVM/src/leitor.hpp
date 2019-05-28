#ifndef LEITOR_H
#define LEITOR_H

#include <stdlib.h>
#include <cstdio>
#include <cstring>
#include <fstream>
#include <iostream>
#include <string>

#include "class_file.hpp"
#include "correct_endian.hpp"
#include "cp_info.h"
#include "field_info.h"
#include "method_info.h"

using namespace std;

class Reader {
   public:
    static ClassFile getClassFile(string);

   private:
    Reader() {}
    static void read_magic(ifstream &, ClassFile *);
    static void read_minor_version(ifstream &, ClassFile *);
    static void read_major_version(ifstream &, ClassFile *);
    static void read_cpool_count(ifstream &, ClassFile *);
    static void read_constant_pool(ifstream &, ClassFile *);
    static void read_access_flags(ifstream &, ClassFile *);
    static void read_this_class(ifstream &, ClassFile *);
    static void read_super_class(ifstream &, ClassFile *);
    static void read_interfaces(ifstream &, ClassFile *);
    static void read_fields(ifstream &, ClassFile *);
    static void read_methods(ifstream &, ClassFile *);
    static void read_attributes(ifstream &, ClassFile *);
};
int comparaIgual(CONSTANT_Utf8_info utf8_struct, std::string nomeAttributo);
void read_field(ifstream &, field_info *);
attribute_info read_attribute(ifstream &, ClassFile *);
//carregar os atributos nas funções abaixo....
ConstantValue_attribute loadConstantValueAttribute();
Code_attributes loadCodeAttribute();
Exceptions_attribute loadExceptionAttribute();
InnerClasses_attribute loadInnerClassAttribute();
Syntethic_attribute loadSyntethicAttribute();
SourceFile_attribute loadSourceFileAttribute();
LineNumberTable_attributes loadNumberTableAttribute();
LocalVariableTable_attribute loadLocalVariableTableInfo();
Deprecated_attribute loadDeprecatedAttributeInfo();



#endif
