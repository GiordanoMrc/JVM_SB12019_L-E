#ifndef ENDIAN_H
#define ENDIAN_H
#include <stdint.h>
#include <fstream>

typedef uint8_t u1;
typedef uint16_t u2;
typedef uint32_t u4;
typedef uint64_t u8;

namespace CorrectEndian {
u2 t_u2(u2);
u4 t_u4(u4);
u8 t_u8(u8);
};  // namespace CorrectEndian

u1 readf_u1(u1 *, std::ifstream &, int);

#define readt_(type, tam)                                                \
    type readf_##type(type *pointer, std::ifstream &file, int n_count) { \
        type aux;                                                        \
        for (int i = 0; i < n_count; i++) {                              \
            file.read((char *)&aux, tam);                                \
            aux = CorrectEndian::t_##type(aux);                          \
            *(pointer + i) = aux;                                        \
        }                                                                \
        return (aux);                                                    \
    }

#endif
