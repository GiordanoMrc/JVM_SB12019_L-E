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

void read_field(ifstream &, ClassFile *, field_info *);
void read_attribute(ifstream &, ClassFile *, attribute_info *);

#endif
