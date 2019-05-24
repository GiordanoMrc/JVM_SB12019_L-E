#ifndef ACCESS_FLAGS_H
#define ACCESS_FLAGS_H
#include "attribute_info.h"
#include "data_types.h"
namespace AccessFlags {
enum {
    ACC_PUBLIC = 0x0001,
    ACC_PRIVATE = 0x0002,
    ACC_PROTECTED = 0x0004,
    ACC_STATIC = 0x0008,
    ACC_FINAL = 0x0010,
    ACC_VOLATILE = 0x0040,
    ACC_TRANSIENT = 0x0080
};
}

#endif