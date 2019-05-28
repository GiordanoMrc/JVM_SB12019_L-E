#ifndef ATTRIBUTE_INFO_H
#define ATTRIBUTE_INFO_H
#include "data_types.h"

typedef struct attribute_info attribute_info;
typedef union info_attribute info_attribute;

typedef struct ConstantValue_attribute ConstantValue_attribute;
typedef struct Exception_table_info Exception_table_info;
typedef struct Code_attributes Code_attributes;
typedef struct Exceptions_attribute Exceptions_attribute;
typedef struct classes_info classes_info;
typedef struct Syntethic_attribute Syntethic_attribute;
typedef struct SourceFile_attribute SourceFile_attribute;
typedef struct LineNumberTable_attributes LineNumberTable_attributes;
typedef struct lineNumberTable lineNumberTable;
typedef struct LocalVariableTable_attribute LocalVariableTable_attribute;
typedef struct local_variable_table local_variable_table;
typedef struct Deprecated_attribute Deprecated_attribute;

struct SourceFile_attribute {
    u2 sourcefile_index;
};

struct lineNumberTable {
    u2 start_pc;
    u2 line_number;
};
struct LineNumberTable_attributes {
    u2 line_number_table_length;
    lineNumberTable* lineTable;
};
struct local_variable_table {
    u2 start_pc;
    u2 length;
    u2 name_index;
    u2 descriptor_index;
    u2 index;
};

struct LocalVariableTable_attribute {
    u2 local_variable_table_length;
    local_variable_table* local_table;
};

struct Deprecated_attribute {
    // vazio
};
// teste!

struct ConstantValue_attribute {
    u2 attribute_name_index;
    u4 attribute_length;
    u2 constantvalue_index;
};

struct Exception_table_info {
    u2 start_pc;
    u2 end_pc;
    u2 handler_pc;
    u2 catch_type;
};

struct Code_attributes {
    u2 attribute_name_index;
    u4 attribute_length;
    u2 max_stack;
    u2 max_locals;
    u4 code_length;
    u1* code;
    u2 exception_table_length;
    Exception_table_info* exception_table;
    u2 attributes_count;
    struct attribute_info* attributes;
};

struct classes_info {
    u2 inner_class_info_index;
    u2 outer_class_info_index;
    u2 inner_name_index;
    u2 inner_class_access_flags;
};

struct InnerClasses_attribute {
    u2 number_of_classes;
    classes_info* classes;
};

struct Exceptions_attribute {
    u2 number_of_exceptions;
    u2* exceptions_index_table;
};

struct Syntethic_attribute {
    // ela nao possui nenhum atributo principal.
};

struct attribute_info {
    u2 attribute_name_index;
    u4 attribute_length;
    info_attribute* info;
};

union info_attribute {
    InnerClasses_attribute innerClasses_attribute_info;
    Code_attributes code_info;
    ConstantValue_attribute constantValue_Info;
    Exceptions_attribute exceptions_info;
    Syntethic_attribute syntethic_attribute;
    SourceFile_attribute sourceFile_attribute;
    LineNumberTable_attributes lineNumberTable_info;
    LocalVariableTable_attribute localVariableTable_info;
    Deprecated_attribute Deprecated_attribute_info;
};

#endif
