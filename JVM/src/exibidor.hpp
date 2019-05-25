#ifndef EXIBIDOR_H
#define EXIBIDOR_H

#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include <string>
#include "access_flags.hpp"
#include "class_file.hpp"
#include "cp_info.h"
#include "field_info.h"
#include "method_info.h"

class Printer {
   public:
    static void showClassFile(ClassFile);

   private:
    static void print_magic(ClassFile);
    static void print_minor_version(ClassFile);
    static void print_major_version(ClassFile);
    static void print_cpool_count(ClassFile);
    static void print_access_flags(ClassFile);
    static void print_this_class(ClassFile);
    static void print_super_class(ClassFile);
    static void print_interfaces_count(ClassFile);
    static void print_interfaces(ClassFile);
    static void print_fields_count(ClassFile);
    static void print_fields(ClassFile);
    static void print_methods(ClassFile);
    static void print_methods_count(ClassFile);
    static void print_attributes_count(ClassFile);
    static void print_attributes(ClassFile);
};

#endif