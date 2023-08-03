#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>

/* [S2] Bitwise operation: high order bits
 *
 * https://inginious.info.ucl.ac.be/course/LEPL1503/s2_bits_leftmost
 * Write the body of a function get_3_leftmost_bits that returns the 3 high order bits of x.
 * For instance, if x=0b11011001..., the function should return a uint8_t containing 0b00000110.
 * If x=0b01100001..., the function should return a uint8_t containing 0b00000011.
*/
uint8_t get_3_leftmost_bits(uint32_t x) {
    return x >> (32-3);
}

/* [S2] Bitwise operation: extract low order bits
 *
 * https://inginious.info.ucl.ac.be/course/LEPL1503/s2_bits_rightmost
 * Write the body of a function get_4_rightmost_bits that returns the 4 low order bits of x.
 * For instance, if x=0b...11011001, the function should return a uint8_t containing 0b00001001.
 *  If x=0b...11011101, your function should return 0b00001101.
 */
uint8_t get_4_rightmost_bits(uint32_t x) {
    return x & 0b1111;
}


/* [S2] Bitwise operation: setting a bit
 *
 * https://inginious.info.ucl.ac.be/course/LEPL1503/s2_bits_set
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
 *  example: see main
*/
uint64_t set_bit(uint64_t x, int pos, bool value) {
    return (x >> (pos+1) << 1 | value) << pos | x << (64-pos) >> (64-pos);
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
    x=0b0000000000000000000000000000000000000000000000000000000011111111;
    printf("set_bit( %llu, 0, true) = %llu\n", x, set_bit(x, 0, true));
    printf("set_bit( %llu, 0, false) = %llu\n", x, set_bit(x, 0, false));
    printf("set_bit( %llu, 1, true) = %llu\n", x, set_bit(x, 1, true));
    printf("set_bit( %llu, 1, false) = %llu\n", x, set_bit(x, 1, false));
    printf("set_bit( %llu, 2, true) = %llu\n", x, set_bit(x, 2, true));
    printf("set_bit( %llu, 2, false) = %llu\n", x, set_bit(x, 2, false));
    printf("set_bit( %llu, 3, true) = %llu\n", x, set_bit(x, 3, true));
    printf("set_bit( %llu, 3, false) = %llu\n", x, set_bit(x, 3, false));
    printf("set_bit( %llu, 4, true) = %llu\n", x, set_bit(x, 4, true));
    printf("set_bit( %llu, 4, false) = %llu\n", x, set_bit(x, 4, false));
    printf("set_bit( %llu, 5, true) = %llu\n", x, set_bit(x, 5, true));
    printf("set_bit( %llu, 5, false) = %llu\n", x, set_bit(x, 5, false));
    printf("set_bit( %llu, 6, true) = %llu\n", x, set_bit(x, 6, true));
    printf("set_bit( %llu, 6, false) = %llu\n", x, set_bit(x, 6, false));
    printf("set_bit( %llu, 7, true) = %llu\n", x, set_bit(x, 7, true));
    printf("set_bit( %llu, 7, false) = %llu\n", x, set_bit(x, 7, false));
    printf("set_bit( %llu, 8, true) = %llu\n", x, set_bit(x, 8, true));
    printf("set_bit( %llu, 8, false) = %llu\n", x, set_bit(x, 8, false));
    printf("set_bit( %llu, 9, true) = %llu\n", x, set_bit(x, 9, true));
    printf("set_bit( %llu, 9, false) = %llu\n", x, set_bit(x, 9, false));
    printf("set_bit( %llu, 10, true) = %llu\n", x, set_bit(x, 10, true));
    printf("set_bit( %llu, 10, false) = %llu\n", x, set_bit(x, 10, false));
}
