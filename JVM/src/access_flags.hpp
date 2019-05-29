#ifndef ACCESS_FLAGS_H
#define ACCESS_FLAGS_H
#include "attribute_info.h"
#include "data_type.hpp"
namespace AccessFlags {
enum {
    PUBLIC = 0x0001,
    FINAL = 0x0010,
    SUPER = 0x0002,
    INTERFACE = 0x0200,
    ABSTRACT = 0x0400,
    SYNTHETIC = 0x1000,
    ANNOTATION = 0x2000,
    ENUM = 0x4000
};
}

#endif