#include "data_type.hpp"

u1 readt_u1(u1 *pointer, std::ifstream &file, int n_count) {
    file.read((char *)pointer, n_count);
    return *pointer;
}

readt_(u2, 2);
readt_(u4, 4);
readt_(u8, 8);

// reverse byte order (16-bit)
u2 CorrectEndian::t_u2(u2 byte) {
    return (byte & 0xFFU) << 8 | (byte & 0xFF00U) >> 8;
}

// reverse byte order (32-bit)
u4 CorrectEndian::t_u4(u4 byte) {
    return (byte & 0x000000FFU) << 24 | (byte & 0x0000FF00U) << 8 |
           (byte & 0x00FF0000U) >> 8 | (byte & 0xFF000000U) >> 24;
}
// reverse byte order (64-bit)
u8 CorrectEndian::t_u8(u8 byte) {
    return (byte & 0x00000000000000FFUL) << 56 |
           (byte & 0x000000000000FF00UL) << 40 |
           (byte & 0x0000000000FF0000UL) << 24 |
           (byte & 0x00000000FF000000UL) << 8 |
           (byte & 0x000000FF00000000UL) >> 8 |
           (byte & 0x0000FF0000000000UL) >> 24 |
           (byte & 0x00FF000000000000UL) >> 40 |
           (byte & 0xFF00000000000000UL) >> 56;
}