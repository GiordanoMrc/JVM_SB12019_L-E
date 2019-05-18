#ifndef CP_INFO_H
#define CP_INFO_H
#include <stdio.h>
#include <stdlib.h>
#include "./data_types.h"
//#include <string.h>
// declaração de tipos e funções

typedef enum tag {
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
} tag;

typedef struct cp_info {
    u1 tag;
    union info {
        struct CONSTANT_Class_info {
            u2 name_index;
        };

        struct CONSTANT_Fieldref_info {
            u2 class_index;
            u2 name_and_type_index;
        };

        struct CONSTANT_NameAndType_info {
            u2 name_index;
            u2 descriptor_index;
        };

        struct CONSTANT_Utf8_info {
            u2 length;
            u1 *bytes;
        };

        struct CONSTANT_Methodref_info {
            u2 class_index;
            u2 name_and_type_index;
        };

        struct CONSTANT_InterfaceMethodref_info {
            u2 class_index;
            u2 name_and_type_index;
        };

        struct CONSTANT_String_info {
            u2 string_index;
        };

        struct CONSTANT_Integer_info {
            u4 bytes;
        };

        struct CONSTANT_Integer_info {
            u4 bytes;
        };

        struct CONSTANT_Float_info {
            u4 bytes;
        };

        struct CONSTANT_Long_info {
            u4 high_bytes;
            u4 low_bytes;
        };

        struct CONSTANT_Double_info {
            u4 high_bytes;
            u4 low_bytes;
        };
    };
} cp_info;

#endif