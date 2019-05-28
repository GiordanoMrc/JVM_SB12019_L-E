#ifndef EXIBIDOR_H
#define EXIBIDOR_H

#include <stdio.h>
#include <stdlib.h>
#include <cstdint>
#include <cstring>
#include <fstream>
#include <iostream>
#include <string>
#include "access_flags.hpp"
#include "class_file.hpp"
#include "cp_info.h"
#include "field_info.h"
#include "method_info.h"

using namespace std;

class Printer {
   public:
    static void showClassFile(ClassFile);

    static void getIndex_Utf8_Ref(cp_info*, u2);
    static void print_magic(ClassFile);
    static void print_minor_version(ClassFile);
    static void print_major_version(ClassFile);
    static void print_cpool_count(ClassFile);
    static void print_constant_pool(ClassFile);
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

void print_attribute(ClassFile, attribute_info, int);
int get_info_attribute_type(ClassFile, info_attribute);

#endif