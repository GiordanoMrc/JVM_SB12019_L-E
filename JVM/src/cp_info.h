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
    CONSTANT_Utf8 = 1
};
}
typedef struct CONSTANT_Class_info {
    u1 tag;
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
    } info;
};

#endif