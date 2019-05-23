#include "correct_endian.hpp"

u2 CorrectEndian::t_u2(u2 byte) { return (byte << 8) | (byte >> 8); }

u4 CorrectEndian::t_u4(u4 byte) {
    byte = ((byte << 8) & 0xFF00FF00) | ((byte >> 8) & 0xFF00FF);
    return (byte << 16) | (byte >> 16);
}

u8 CorrectEndian::t_u8(u8 byte) {
    byte = ((byte << 8) & 0xFF00FF00FF00FF00ULL) |
           ((byte >> 8) & 0x00FF00FF00FF00FFULL);
    byte = ((byte << 16) & 0xFFFF0000FFFF0000ULL) |
           ((byte >> 16) & 0x0000FFFF0000FFFFULL);
    return (byte << 32) | (byte >> 32);
}