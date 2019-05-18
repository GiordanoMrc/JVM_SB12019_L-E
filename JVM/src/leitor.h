#ifndef LEITOR_H
#define LEITOR_H
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include "types/cp_info.h"
#include "types/field_info.h"
#include "types/method_info.h"
//#include <string.h>
// declaração de tipos e funções

typedef struct classFile {
    u4 magic;          // cafebabe
    u2 minor_version;  // formato da versão M.m
    u2 major_version;
    u2 constant_pool_count;  // contador da constant pool
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
} classFile;

#endif