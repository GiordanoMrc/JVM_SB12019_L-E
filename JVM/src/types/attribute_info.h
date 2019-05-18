#ifndef ATTRIBUTE_INFO_H
#define ATTRIBUTE_INFO_H
#include "./data_types.h"

typedef struct attribute_info {
    u2 attribute_name_index;
    u4 attribute_length;
    u1 *info;
};

#endif