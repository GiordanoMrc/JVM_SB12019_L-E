#ifndef LEITOR__HELPER_H
#define LEITOR__HELPER_H

#include <fstream>
#include <string>

#include "attribute_info.h"
#include "class_file.hpp"
#include "data_type.hpp"

int get_info_attribute_type(CONSTANT_Utf8_info);
void read_info_attribute(std::ifstream &, ClassFile *, info_attribute *info);
void read_attribute(std::ifstream &, ClassFile *, attribute_info *);

#endif