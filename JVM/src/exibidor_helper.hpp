#ifndef GET_CONSTANT_H
#define GET_CONSTANT_H
#include <cstring>
#include <iostream>
#include "class_file.hpp"
#include "cp_info.h"
#include "data_type.hpp"
#include "leitor_helper.hpp"

u1 *get_end_index_utf8_bytes(cp_info *, u2);
void get_Access_Flag_Field1(u2);
void get_Access_Flag_Field2(u2);
void print_attribute(ClassFile, attribute_info, int);
#endif