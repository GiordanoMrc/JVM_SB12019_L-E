#ifndef CP_INFO_H
#define CP_INFO_H
#include "data_types.h"
namespace ConstantPoolTags {
enum {
    CONSTANT_Class = 7,
    CONSTANT_Fieldref = 9,
    CONSTANT_Methodref = 10,
    CONSTANT_InterfaceMethodref = 11,
    CONSTANT_String = 8,
    CONSTANT_Integer = 3,
    CONSTANT_Float = 4,
    CONSTANT_Long = 5,
    CONSTANT_Double = 6,
    CONSTANT_NameAndType = 12,
    CONSTANT_Utf8 = 1,
    CONSTANT_NULL =0,
    CONSTANT_MethodHandle = 15,
    CONSTANT_MethodType = 16,
    CONSTANT_InvokeDynamic = 18
};
}
typedef struct CONSTANT_Class_info {
    u2 name_index;
} CONSTANT_Class_info;

typedef struct CONSTANT_Fieldref_info {
    u2 class_index;
    u2 name_and_type_index;
} CONSTANT_Fieldref_info;

typedef struct CONSTANT_NameAndType_info {
    u2 name_index;
    u2 descriptor_index;
} CONSTANT_NameAndType_info;

typedef struct CONSTANT_Utf8_info {
    u2 length;
    u1 *bytes;
} CONSTANT_Utf8_info;

typedef struct CONSTANT_Methodref_info {
    u2 class_index;
    u2 name_and_type_index;
} CONSTANT_Methodref_info;

typedef struct CONSTANT_InterfaceMethodref_info {
    u2 class_index;
    u2 name_and_type_index;
} CONSTANT_InterfaceMethodref_info;

typedef struct CONSTANT_String_info {
    u2 string_index;
} CONSTANT_String_info;

typedef struct CONSTANT_Integer_info {
    u4 bytes;
} CONSTANT_Integer_info;

typedef struct CONSTANT_Float_info {
    u4 bytes;
} CONSTANT_Float_info;

typedef struct CONSTANT_Long_info {
    u4 high_bytes;
    u4 low_bytes;
} CONSTANT_Long_info;

typedef struct CONSTANT_Double_info {
    u4 high_bytes;
    u4 low_bytes;
} CONSTANT_Double_info;


//teste!

typedef struct ConstantValue_attribute{
    u2 attribute_name_index;
    u4 attribute_length;
    u2 constantvalue_index;

}ConstantValue_attribute;

typedef struct Exception_table_info{
    u2 start_pc;
    u2 end_pc;
    u2 handler_pc;
    u2 catch_type;

}Exception_table_info;


typedef struct Code_attributes {
    u2 attribute_name_index;
    u4 attribute_length;
    u2 max_stack;
    u2 max_locals;
    u4 code_length;
    u1* code;
    u2 exception_table_length;
    Exception_table_info* exception_table;
    u2 attributes_count;
    attribute_info* attributes;
}Code_attributes;

typedef struct classes_info{
    u2 inner_class_info_index;
    u2 outer_class_info_index;
    u2 inner_name_index;
    u2 inner_class_access_flags;
}classes_info;

typedef struct InnerClasses_attribute{
    u2 number_of_classes;
    classes_info* classes;
}InnerClasses_attribute;


typedef struct Exceptions_attribute{
    u2 number_of_exceptions;
    u2* exceptions_index_table;
}Exceptions_attribute;


typedef struct Syntethic_attribute{
    // ela nao possui nenhum atributo principal.
} Syntethic_attribute;


typedef struct field_info {
    u2 access_flags;
    u2 name_index;
    u2 descriptor_index;
    u2 attributes_count;
    attribute_info* attributes;
}field_info;

typedef struct attribute_info{
    u2 attribute_name_index;
    u4 attribute_length;
    union{
        InnerClasses_attribute innerClasses_attribute_info;
        Code_attributes code_info;
        ConstantValue_attribute constantValue_Info;
        Exceptions_attribute exceptions_info;
        Syntethic_attribute syntethic_attribute;
        SourceFile_attribute sourceFile_attribute;
        LineNumberTable_attributes lineNumberTable_info;
        LocalVariableTable_attribute localVariableTable_info;
        Deprecated_attribute Deprecated_attribute_info;
    }info;

};
struct MethodInfo {
    u2 access_flags;
    u2 name_index;
    u2 descriptor_index;
    u2 attributes_count;
    attribute_info* attributes;

};
//acabou teste


struct cp_info {
    u1 tag;
    union info {
        struct CONSTANT_Class_info class_info;
        struct CONSTANT_Fieldref_info fieldref_info;
        struct CONSTANT_NameAndType_info nameandtype_info;
        struct CONSTANT_Utf8_info utf8_info;
        struct CONSTANT_Methodref_info methodref_info;
        struct CONSTANT_InterfaceMethodref_info interfacemethodref_info;
        struct CONSTANT_String_info string_info;
        struct CONSTANT_Integer_info integer_info;
        struct CONSTANT_Float_info float_info;
        struct CONSTANT_Long_info long_info;
        struct CONSTANT_Double_info double_info;
        struct CONSTANT_MethodHandle_info methodhandle_info;
        struct CONSTANT_MethodType_info methodtype_info;
        struct CONSTANT_InvokeDynamic_info invokedynamic_info;
    } info;
};

#endif
