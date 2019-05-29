#include "get_constant.hpp"

CONSTANT_Class_info getConstantClassInfo(std::ifstream &file) {
    CONSTANT_Class_info aux;
    readt_u2(&aux.name_index, file, 1);
    return aux;
}

CONSTANT_Fieldref_info getConstantFieldRef(std::ifstream &file) {
    CONSTANT_Fieldref_info aux;
    readt_u2(&aux.class_index, file, 1);
    readt_u2(&aux.name_and_type_index, file, 1);
    return aux;
}

CONSTANT_NameAndType_info getConstantNameAndTypeInfo(std::ifstream &file) {
    CONSTANT_NameAndType_info aux;
    readt_u2(&aux.name_index, file, 1);
    readt_u2(&aux.descriptor_index, file, 1);
    return aux;
}

CONSTANT_Utf8_info getConstantUtf8Info(std::ifstream &file) {
    CONSTANT_Utf8_info aux;
    readt_u2(&aux.length, file, 1);
    aux.bytes = (u1 *)malloc(sizeof(u1) * aux.length + 1);
    readt_u1(aux.bytes, file, aux.length);
    aux.bytes[aux.length] = '\0';
    return aux;
}

CONSTANT_Methodref_info getConstantMethodRefInfo(std::ifstream &file) {
    CONSTANT_Methodref_info aux;
    readt_u2(&aux.class_index, file, 1);
    readt_u2(&aux.name_and_type_index, file, 1);
    return aux;
}

CONSTANT_InterfaceMethodref_info getConstantInterfaceMethodRefInfo(
    std::ifstream &file) {
    CONSTANT_InterfaceMethodref_info aux;
    readt_u2(&aux.class_index, file, 1);
    readt_u2(&aux.name_and_type_index, file, 1);
    return aux;
}

CONSTANT_String_info getConstantStringInfo(std::ifstream &file) {
    CONSTANT_String_info aux;
    readt_u2(&aux.string_index, file, 1);
    return aux;
}

CONSTANT_Integer_info getConstantIntegerInfo(std::ifstream &file) {
    CONSTANT_Integer_info aux;
    readt_u4(&aux.bytes, file, 1);
    return aux;
}

CONSTANT_Float_info getConstantFloatInfo(std::ifstream &file) {
    CONSTANT_Float_info aux;
    readt_u4(&aux.bytes, file, 1);
    return aux;
}

CONSTANT_Long_info getConstantLongInfo(std::ifstream &file) {
    CONSTANT_Long_info aux;
    readt_u4(&aux.high_bytes, file, 1);
    readt_u4(&aux.low_bytes, file, 1);
    return aux;
}

CONSTANT_Double_info getConstantDoubleInfo(std::ifstream &file) {
    CONSTANT_Double_info aux;
    readt_u4(&aux.high_bytes, file, 1);
    readt_u4(&aux.low_bytes, file, 1);
    return aux;
}

CONSTANT_MethodHandle_info getConstantMethodHandleInfo(std::ifstream &file) {
    CONSTANT_MethodHandle_info aux;
    readt_u1(&aux.reference_kind, file, 1);
    readt_u2(&aux.reference_index, file, 1);
    return aux;
}

CONSTANT_MethodType_info getConstantMethodTypeInfo(std::ifstream &file) {
    CONSTANT_MethodType_info aux;
    readt_u2(&aux.descriptor_index, file, 1);
    return aux;
}

CONSTANT_InvokeDynamic_info getConstantInvokeDynamicInfo(std::ifstream &file) {
    CONSTANT_InvokeDynamic_info aux;
    readt_u2(&aux.bootstrap_method_attr_index, file, 1);
    readt_u2(&aux.name_and_type_index, file, 1);
    return aux;
}
