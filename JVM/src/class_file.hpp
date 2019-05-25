#ifndef CLASS_FILE_H
#define CLASS_FILE_H

#include "cp_info.h"
#include "field_info.h"
#include "method_info.h"

class ClassFile {
   public:
    u4 magic = 0x00;       // cafebabe
    u2 minor_version = 0;  // formato da versão M.m
    u2 major_version = 0;
    u2 cp_count = 0;
    cp_info *constant_pool = NULL;  // constantpool sendo ponteiro p/ cp_info
    u2 access_flags = 0x00;
    u2 this_class = 0;
    u2 super_class = 0;
    u2 interfaces_count = 0;
    u2 *interfaces = NULL;
    u2 fields_count = 0;
    field_info *fields = NULL;
    u2 methods_count = 0;
    method_info *methods = NULL;
    u2 attributes_count = 0;
    attribute_info *attributes = NULL;

    ClassFile() {}
};

#endif