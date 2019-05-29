#ifndef GET_CONTANT__H
#define GET_CONTANT__H
#include <fstream>

#include "cp_info.h"
#include "data_type.hpp"
#include "field_info.h"
#include "method_info.h"

CONSTANT_Class_info getConstantClassInfo(std::ifstream &);
CONSTANT_Fieldref_info getConstantFieldRef(std::ifstream &);
CONSTANT_NameAndType_info getConstantNameAndTypeInfo(std::ifstream &);
CONSTANT_Utf8_info getConstantUtf8Info(std::ifstream &);
CONSTANT_Methodref_info getConstantMethodRefInfo(std::ifstream &);
CONSTANT_InterfaceMethodref_info getConstantInterfaceMethodRefInfo(
    std::ifstream &);
CONSTANT_String_info getConstantStringInfo(std::ifstream &);
CONSTANT_Integer_info getConstantIntegerInfo(std::ifstream &);
CONSTANT_Float_info getConstantFloatInfo(std::ifstream &);
CONSTANT_Long_info getConstantLongInfo(std::ifstream &);
CONSTANT_Double_info getConstantDoubleInfo(std::ifstream &);
CONSTANT_MethodHandle_info getConstantMethodHandleInfo(std::ifstream &);
CONSTANT_MethodType_info getConstantMethodTypeInfo(std::ifstream &);
CONSTANT_InvokeDynamic_info getConstantInvokeDynamicInfo(std::ifstream &);

#endif