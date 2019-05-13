#ifndef LEITOR_H
#define LEITOR_H
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
//#include <string.h>
// declaração de tipos e funções

typedef struct classFile {
    uint32_t magic;               //cafebabe
    uint16_t minor_version;       // formato da versão M.m
    uint16_t major_version;       
    uint16_t constant_pool_count;  //contador da constant pool
    cp_info *constant_pool;        //constantpool sendo ponteiro p/ cp_info
    uint16_t access_flags;        
    uint16_t this_class;          
    uint16_t super_class;         
    uint16_t interfaces_count;    
    uint16_t *interfaces;         
    uint16_t fields_count;        
    field_info *fields;           
    uint16_t methods_count;      
    method_info *methods;         
    uint16_t attributes_count;   
    attribute_info *attributes;   
} classFile;

#endif