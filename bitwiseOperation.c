#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>
#include <inttypes.h>

/*
 * Write the body of a function that returns the value of variable x, but modified with the bit at position pos set to value.
 * Remember that in C (this is defined in stdbool.h), true corresponds to integer 1 while false corresponds to integer 0.
 * Remember than in C, you can create a mask as a binary value and use it with the bitwise and (&) and or (|) operations.
 * For example:
 *       uint8_t a=0b00000000;
 *       uint8_t b=0b00001000;
 *       uint8_t c=0b11111101;
 *       uint8_t d=0b11011011;
 *       // ~(a) returns 0b11111111
 *       // (c&a) returns 0b00000000
 *       // (c&b) returns 0b00001000
 *       // (a|b) returns 0b00001000
 *       // (d&c) returns 0b11011001
 *
 * @pre 0<= pos < 64
 *  example:
*/
uint64_t set_bit(uint64_t x, int pos, bool value) {
    if (pos == 0) { return x >> 1 << 1 | value; }
    if (pos == 63) { return (0b1000000000000000000000000000000000000000000000000000000000000000 * value) | x << 1 >> 1 ;}
    return ((((x >> pos) << 1) | value) << (pos - 1)) | ((x << (64 - pos)) >> (65 - pos));
}

int main(int argc, char **argv) {
    uint64_t x = 0b0000000000000000000000000000000000000000000000000000000000000000;
    printf("set_bit( %llu, 4, true) = %llu\n", x, set_bit(x, 4, true));
    printf("set_bit( %llu, 4, false) = %llu\n", x, set_bit(x, 4, false));
    x = 0b1000000000000000000000000000000000000000000000000000000000000000;
    printf("set_bit( %llu, 4, true) = %llu\n", x, set_bit(x, 4, true));
    printf("set_bit( %llu, 4, false) = %llu\n", x, set_bit(x, 4, false));
    printf("set_bit( %llu, 0, true) = %llu\n", x, set_bit(x, 0, true));
    printf("set_bit( %llu, 0, false) = %llu\n", x, set_bit(x, 0, false));
    printf("set_bit( %llu, 63, true) = %llu\n", x, set_bit(x, 63, true));
    printf("set_bit( %llu, 63, false) = %llu\n", x, set_bit(x, 63, false));
    printf("set_bit( %llu, 1, true) = %llu\n", x, set_bit(x, 1, true));
    printf("set_bit( %llu, 1, false) = %llu\n", x, set_bit(x, 1, false));
    printf("set_bit( %llu, 62, true) = %llu\n", x, set_bit(x, 62, true));
    printf("set_bit( %llu, 62, false) = %llu\n", x, set_bit(x, 62, false));
    x = 0b10000000000000000000000000000000;
    printf("set_bit( %llu, 4, true) = %llu\n", x, set_bit(x, 4, true));
    printf("set_bit( %llu, 4, false) = %llu\n", x, set_bit(x, 4, false));
    printf("set_bit( %llu, 0, true) = %llu\n", x, set_bit(x, 0, true));
    printf("set_bit( %llu, 0, false) = %llu\n", x, set_bit(x, 0, false));
    printf("set_bit( %llu, 63, true) = %llu\n", x, set_bit(x, 63, true));
    printf("set_bit( %llu, 63, false) = %llu\n", x, set_bit(x, 63, false));
    printf("set_bit( %llu, 1, true) = %llu\n", x, set_bit(x, 1, true));
    printf("set_bit( %llu, 1, false) = %llu\n", x, set_bit(x, 1, false));
    printf("set_bit( %llu, 62, true) = %llu\n", x, set_bit(x, 62, true));
    printf("set_bit( %llu, 62, false) = %llu\n", x, set_bit(x, 62, false));
    x = 0b0000000000000000000001110000000000000000000000000000000000111111;
    printf("set_bit( %llu, 4, true) = %llu\n", x, set_bit(x, 4, true));
    printf("set_bit( %llu, 4, false) = %llu\n", x, set_bit(x, 4, false));
    printf("set_bit( %llu, 0, true) = %llu\n", x, set_bit(x, 0, true));
    printf("set_bit( %llu, 0, false) = %llu\n", x, set_bit(x, 0, false));
    printf("set_bit( %llu, 63, true) = %llu\n", x, set_bit(x, 63, true));
    printf("set_bit( %llu, 63, false) = %llu\n", x, set_bit(x, 63, false));
    x=0b11111111;
    printf("set_bit( %llu, 8, true) = %llu\n", x, set_bit(x, 8, true));
    printf("set_bit( %llu, 8, false) = %llu\n", x, set_bit(x, 8, false));
}
