#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include <string>
#include "class_file.h"
#include "cp_info.h"
#include "field_info.h"
#include "method_info.h"

#ifndef EXIBIDOR_H
#define EXIBIDOR_H
// declaração de tipos e funções

class Printer {
   public:
    static void showClassFile(ClassFile);

   private:
    static void print_magic(ClassFile);
    static void print_minor_version(ClassFile);
    static void print_major_version(ClassFile);
    static void print_cpool_size(ClassFile);
    static void print_access_flags(ClassFile);
    static void print_this_class(ClassFile);
    static void print_super_class(ClassFile);
    static void print_interfaces(ClassFile);
    static void print_fields(ClassFile);
    static void print_methods(ClassFile);
    static void print_attributes(ClassFile);
};

#endif