#include "exibidor_helper.hpp"

u1 *get_end_index_utf8_bytes(cp_info *constant_pool, u2 index) {
    cp_info *cp = constant_pool + index - 1;
    float aux = 0;

    if (cp->tag == 1) {
        return cp->info.utf8_info.bytes;
    }
    switch (cp->tag) {
        case (ConstantPoolTags::CONSTANT_Float):
            memcpy(&aux, &(cp->info.float_info.bytes), sizeof(float));
            std::cout << aux;
            break;
        case (ConstantPoolTags::CONSTANT_Class):
            get_end_index_utf8_bytes(constant_pool,
                                     cp->info.class_info.name_index);
            break;
        case (ConstantPoolTags::CONSTANT_Fieldref):
            get_end_index_utf8_bytes(constant_pool,
                                     cp->info.fieldref_info.class_index);
            std::cout << ".";
            get_end_index_utf8_bytes(
                constant_pool, cp->info.fieldref_info.name_and_type_index);
            break;
        case (ConstantPoolTags::CONSTANT_Methodref):
            get_end_index_utf8_bytes(constant_pool,
                                     cp->info.methodref_info.class_index);
            std::cout << ".";
            get_end_index_utf8_bytes(
                constant_pool, cp->info.methodref_info.name_and_type_index);
            break;
        case (ConstantPoolTags::CONSTANT_NameAndType):
            get_end_index_utf8_bytes(constant_pool,
                                     cp->info.nameandtype_info.name_index);
            std::cout << ".";
            get_end_index_utf8_bytes(
                constant_pool, cp->info.nameandtype_info.descriptor_index);
            break;
        case (ConstantPoolTags::CONSTANT_String):
            get_end_index_utf8_bytes(constant_pool,
                                     (u2)cp->info.string_info.string_index);
            break;
        case (ConstantPoolTags::CONSTANT_InterfaceMethodref):
            get_end_index_utf8_bytes(
                constant_pool, cp->info.interfacemethodref_info.class_index);
            std::cout << ".";
            get_end_index_utf8_bytes(
                constant_pool,
                cp->info.interfacemethodref_info.name_and_type_index);
            break;
        case (ConstantPoolTags::CONSTANT_MethodHandle):
            get_end_index_utf8_bytes(
                constant_pool, cp->info.methodhandle_info.reference_index);
            break;
        case (ConstantPoolTags::CONSTANT_MethodType):
            get_end_index_utf8_bytes(constant_pool,
                                     cp->info.methodtype_info.descriptor_index);
            break;
        case (ConstantPoolTags::CONSTANT_InvokeDynamic):
            get_end_index_utf8_bytes(
                constant_pool,
                cp->info.invokedynamic_info.bootstrap_method_attr_index);
            get_end_index_utf8_bytes(
                constant_pool, cp->info.invokedynamic_info.name_and_type_index);
            break;
        default:
            break;
    }
}
