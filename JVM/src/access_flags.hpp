#ifndef ACCESS_FLAGS_H
#define ACCESS_FLAGS_H
#include "attribute_info.h"
#include "data_types.h"
namespace AccessFlags {
enum {
    PUBLIC = 0x0001,
    PRIVATE = 0x0002,
    FINAL = 0x0010,
    PROTECTED = 0x0004,
    STATIC = 0x0008,
    SUPER = 0x0002,
    INTERFACE = 0x0200,
    VOLATILE = 0x0040,
    ABSTRACT = 0x0400,
    SYNTHETIC = 0x1000,
    ANNOTATION = 0x2000,
    TRANSIENT = 0x0080,
    ENUM = 0x4000
};
}
namespace CONSTANT_ACCESS_FLAGS_INNERFLAGS{
enum{
    INNER_ACC_PUBLIC = 0x0001,
    INNER_ACC_PRIVATE = 0x0002,
    INNER_ACC_PROTECTED = 0x0004,
    INNER_ACC_STATIC = 0x0008,
    INNER_ACC_FINAL = 0x0010,
    INNER_ACC_INTERFACE = 0x0200,
    INNER_ACC_ABSTRACT = 0x0400,
    INNER_ACC_SYNTHETIC = 0x1000,
    INNER_ACC_ANNOTATION = 0x2000,
    INNER_ACC_ENUM = 0x4000
};
}

#endif
