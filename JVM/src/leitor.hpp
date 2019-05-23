#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include <string>

#include "endian.h"
#include "types/class_file.h"
#include "types/cp_info.h"
#include "types/field_info.h"
#include "types/method_info.h"

#ifndef LEITOR_H
#define LEITOR_H
// declaração de tipos e funções

using namespace std;

class Reader {
   public:
    ClassFile getClassFile(string);
    Reader() {}

   private:
    void read_magic(ifstream&, ClassFile*);
    void read_minor_version(ifstream&, ClassFile*);
    void read_major_version(ifstream&, ClassFile*);
    void read_constant_pool(ifstream&, ClassFile*);
    void read_access_flags(ifstream&, ClassFile*);
    void read_this_class(ifstream&, ClassFile*);
    void read_super_class(ifstream&, ClassFile*);
    void read_interfaces(ifstream&, ClassFile*);
    void read_fields(ifstream&, ClassFile*);
    void read_methods(ifstream&, ClassFile*);
    void read_attributes(ifstream&, ClassFile*);
};

#endif