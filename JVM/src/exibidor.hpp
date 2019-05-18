#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include <string>
#include "types/class_file.h"
#include "types/cp_info.h"
#include "types/field_info.h"
#include "types/method_info.h"

#ifndef EXIBIDOR_H
#define EXIBIDOR_H
// declaração de tipos e funções

class Printer {
   public:
    static void showClassFile(ClassFile cf);

   private:
    static void print_magic(ClassFile cf);
    static void print_minor_version();
    static void print_major_version();
    static void print_constant_pool();
    static void print_access_flags();
    static void print_this_class();
    static void print_super_class();
    static void print_interfaces();
    static void print_fields();
    static void print_methods();
    static void print_attributes();
};

#endif