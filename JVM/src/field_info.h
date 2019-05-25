#ifndef FIELD_INFO_H
#define FIELD_INFO_H

#include "attribute_info.h"
#include "data_types.h"

namespace FieldAcessFlags {
enum {
    PUBLIC = 0x0001,
    PRIVATE = 0x0002,
    PROTECTED = 0x0004,
    STATIC = 0x0008,
    FINAL = 0x0010,
    VOLATILE = 0x0040,
    TRANSIENT = 0x0080
};
}

struct field_info {
    u2 access_flags;
    u2 name_index;
    u2 descriptor_index;
    u2 attributes_count;
    attribute_info *attributes;
};

#endif