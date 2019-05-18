#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <string>
#include "types/class_file.h"
#include "types/cp_info.h"
#include "types/field_info.h"
#include "types/method_info.h"

#ifndef LEITOR_H
#define LEITOR_H
// declaração de tipos e funções

class Reader {
   public:
    ClassFile getClassFile(std::string name);
    Reader() {}

   private:
    std::ifstream input;
    void read_magic(ClassFile cf);
    void read_minor_version();
    void read_major_version();
    void read_constant_pool();
    void read_access_flags();
    void read_this_class();
    void read_super_class();
    void read_interfaces();
    void read_fields();
    void read_methods();
    void read_attributes();
};

#endif