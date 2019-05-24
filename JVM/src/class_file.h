#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include "cp_info.h"
#include "field_info.h"
#include "method_info.h"

#ifndef CLASS_FILE_H
#define CLASS_FILE_H


class ClassFile {
   public:
    u4 magic;          // cafebabe
    u2 minor_version;  // formato da versão M.m
    u2 major_version;
    u2 cp_size;  // contador da constant pool
    cp_info *constant_pool;  // constantpool sendo ponteiro p/ cp_info
    u2 access_flags;
    u2 this_class;
    u2 super_class;
    u2 interfaces_count;
    u2 *interfaces;
    u2 fields_count;
    field_info *fields;
    u2 methods_count;
    method_info *methods;
    u2 attributes_count;
    attribute_info *attributes;

    ClassFile() {}
};

#endif