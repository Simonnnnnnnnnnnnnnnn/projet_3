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
    return x >> (32 - 3);
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
    return (x >> (pos + 1) << 1 | value) << pos | x << (64 - pos) >> (64 - pos);
}

/* [S2] Bitwise operation: cycling bits
 *
 * https://inginious.info.ucl.ac.be/course/LEPL1503/s2_bits_spin
 *
 * In this exercise, we will work with operation on bits. When we speak about the position of a bit,
 * index 0 corresponds to lowest order bit, 1 to the second-lowest order bit, ...
 * In C source code, you can write a number in binary (base 2) by prefixing it via 0b., e.g. 0b11010 = 26.
 *
 * This exercise will introduce some non-standard data types which guarantee that the variable has a fixed number of bits.
 * Indeed, on some machines, a int could use 2, 4 or 8 bytes.
 * Hence, if we want to perform bitwise operations, we have to know first on how many bits we are working.
 *
 * For this, C introduces a new class of variable types :
 *
 * int8_t (signed integer of 8 bits)
 * uint8_t (unsigned integer of 8 bits)
 * uint16_t (unsigned integer of 16 bits)
 * You can mix uint or int with bit-lengths 8, 16, 32 and 64). These types are defined in <stdint.h>
 *
 *
 * Write the body of a function cycle_bits, which cycles all bits from n places to the left,
 *    according to the formula x[(i+n)%32] = x[i], where x[i] is the i-iest bit of x.
 * Here is a simple example with bytes.
 * Consider byte                                  0b0110 1011.
 *                                                  abcd efgh
 * If n is set to 1, then cycle_bits would return 0b1101 0110.
 *                                                  hgfe dcba
 * If n is set to 4, then cycle_bits would return 0b1011 0110.
 *                                                  efgh abcd
 */
uint32_t cycle_bits(uint32_t x, uint8_t n) {
    //TODO to fix!
    const uint8_t bits = 8;
    uint32_t rc = 0b0;
    for (int i = 0; i < bits; i++) {
        uint32_t value = (x >> i & 0b1) << (1 - (n + i) % bits);
        rc |= value;
    }
    return rc;
}

/* [S2] Bitwise operation: counting set bits
 *
 * https://inginious.info.ucl.ac.be/course/LEPL1503/s2_bits_sum
 *
 * In this exercise, we will work with operation on bits.
 * When we speak about the position of a bit, index 0 corresponds to lowest order bit, 1 to the second-lowest order bit, ...
 *
 * In C source code, you can write a number in binary (base 2) by prefixing it via 0b., e.g. 0b11010 = 26.
 *
 * This exercise will introduce some non-standard data types which guarantee that the variable has a fixed number of bits.
 * Indeed, on some machines, a int could use 2, 4 or 8 bytes.
 * Hence, if we want to perform bitwise operations, we have to know first on how many bits we are working.
 *
 * Write the body of a function that counts the number of bits set to 1 in its parameter :
 *
 * For example, with bytes you should obtain the following results:
 *
 * nbits(0b00000100) == 1;
 * nbits(0b00000111) == 3;
 * nbits(0b00001010) == 2;
 */
uint8_t nbits(uint32_t n) {
    uint8_t cpt = 0;
    for (int i = 0; i < 32; i++) { cpt += ((n >> i) & 0b1); }
    return cpt;
}

/* [S2] Bitwise operation: resetting the highest order bit
 *
 *  https://inginious.info.ucl.ac.be/course/LEPL1503/s2_bits_strong
 *
 * In this exercise, we will work with operation on bits.
 * When we speak about the position of a bit, index 0 corresponds to lowest order bit, 1 to the second-lowest order bit, ...
 *
 * In C source code, you can write a number in binary (base 2) by prefixing it via 0b., e.g. 0b11010 = 26.
 * This exercise will introduce some non-standard data types which guarantee that the variable has a fixed number of bits.
 * Indeed, on some machines, a int could use 2, 4 or 8 bytes.
 * Hence, if we want to perform bitwise operations, we have to know first on how many bits we are working.
 *
 * Write the body of a function reset_highestorder_bit,
 * which sets to 0 the highest bit set to 1 it founds,
 * and does nothing if there's no bit set to 1.
 *
 * For example, with bytes,
 * reset_highestorder_bit(0b000111010101010) would return 0b000011010101010
 * reset_highestorder_bit(0b100111010101010) would return 0b000111010101010
 *
 * To write this function, you first need to determine the position of the highest order bit
 * that is set to 1 and the reset its value.
 *  ********
 *  * NOTE * this code doesn't work properly on INGInious! always throws an exception
 *  ********
 */
uint32_t reset_highestorder_strong_bit(uint32_t x) {
    uint8_t bits = 32;
    uint8_t strongestBitPosition = bits - 1;
    // loop from left to right until...
    for (strongestBitPosition = bits - 1; strongestBitPosition > 0; strongestBitPosition--) {
        // we break the loop if we find 1
        if ((x >> strongestBitPosition) & 0b1) break;
    }
    // once we have reached our strongest bit position, we can then shift twice to remove it-keeping the remaining bits.
    return x << (bits - strongestBitPosition) >> (bits - strongestBitPosition);
}

void check_set_bit() {
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
    x = 0b0000000000000000000000000000000000000000000000000000000011111111;
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

void check_cycle_bits() {
    uint32_t x = 0b00000000000000000000000000000000;
    x = 0b01101011;

    printf("cycle_bits( %llu, 1) = %llu\n", x, cycle_bits(x, 1));
    printf("cycle_bits( %llu, 4) = %llu\n", x, cycle_bits(x, 4));
    x = 0b10000000000000000000000000000000;
    printf("cycle_bits( %llu, 4) = %llu\n", x, cycle_bits(x, 4));
    printf("cycle_bits( %llu, 4) = %llu\n", x, cycle_bits(x, 4));
    printf("cycle_bits( %llu, 0) = %llu\n", x, cycle_bits(x, 0));
    printf("cycle_bits( %llu, 0) = %llu\n", x, cycle_bits(x, 0));
    printf("cycle_bits( %llu, 63) = %llu\n", x, cycle_bits(x, 63));
    printf("cycle_bits( %llu, 63) = %llu\n", x, cycle_bits(x, 63));
    printf("cycle_bits( %llu, 1) = %llu\n", x, cycle_bits(x, 1));
    printf("cycle_bits( %llu, 1) = %llu\n", x, cycle_bits(x, 1));
    printf("cycle_bits( %llu, 62) = %llu\n", x, cycle_bits(x, 62));
    printf("cycle_bits( %llu, 62) = %llu\n", x, cycle_bits(x, 62));
    x = 0b10000000000000000000000000000000;
    printf("cycle_bits( %llu, 4) = %llu\n", x, cycle_bits(x, 4));
    printf("cycle_bits( %llu, 4) = %llu\n", x, cycle_bits(x, 4));
    printf("cycle_bits( %llu, 0) = %llu\n", x, cycle_bits(x, 0));
    printf("cycle_bits( %llu, 0) = %llu\n", x, cycle_bits(x, 0));
    printf("cycle_bits( %llu, 63) = %llu\n", x, cycle_bits(x, 63));
    printf("cycle_bits( %llu, 63) = %llu\n", x, cycle_bits(x, 63));
    printf("cycle_bits( %llu, 1) = %llu\n", x, cycle_bits(x, 1));
    printf("cycle_bits( %llu, 1) = %llu\n", x, cycle_bits(x, 1));
    printf("cycle_bits( %llu, 62) = %llu\n", x, cycle_bits(x, 62));
    printf("cycle_bits( %llu, 62) = %llu\n", x, cycle_bits(x, 62));
    x = 0b00000000000000000000000000111111;
    printf("cycle_bits( %llu, 4) = %llu\n", x, cycle_bits(x, 4));
    printf("cycle_bits( %llu, 4) = %llu\n", x, cycle_bits(x, 4));
    printf("cycle_bits( %llu, 0) = %llu\n", x, cycle_bits(x, 0));
    printf("cycle_bits( %llu, 0) = %llu\n", x, cycle_bits(x, 0));
    printf("cycle_bits( %llu, 63) = %llu\n", x, cycle_bits(x, 63));
    printf("cycle_bits( %llu, 63) = %llu\n", x, cycle_bits(x, 63));
    x = 0b00000000000000000000000011111111;
    printf("cycle_bits( %llu, 0) = %llu\n", x, cycle_bits(x, 0));
    printf("cycle_bits( %llu, 0) = %llu\n", x, cycle_bits(x, 0));
    printf("cycle_bits( %llu, 1) = %llu\n", x, cycle_bits(x, 1));
    printf("cycle_bits( %llu, 1) = %llu\n", x, cycle_bits(x, 1));
    printf("cycle_bits( %llu, 2) = %llu\n", x, cycle_bits(x, 2));
    printf("cycle_bits( %llu, 2) = %llu\n", x, cycle_bits(x, 2));
    printf("cycle_bits( %llu, 3) = %llu\n", x, cycle_bits(x, 3));
    printf("cycle_bits( %llu, 3) = %llu\n", x, cycle_bits(x, 3));
    printf("cycle_bits( %llu, 4) = %llu\n", x, cycle_bits(x, 4));
    printf("cycle_bits( %llu, 4) = %llu\n", x, cycle_bits(x, 4));
    printf("cycle_bits( %llu, 5) = %llu\n", x, cycle_bits(x, 5));
    printf("cycle_bits( %llu, 5) = %llu\n", x, cycle_bits(x, 5));
    printf("cycle_bits( %llu, 6) = %llu\n", x, cycle_bits(x, 6));
    printf("cycle_bits( %llu, 6) = %llu\n", x, cycle_bits(x, 6));
    printf("cycle_bits( %llu, 7) = %llu\n", x, cycle_bits(x, 7));
    printf("cycle_bits( %llu, 7) = %llu\n", x, cycle_bits(x, 7));
    printf("cycle_bits( %llu, 8) = %llu\n", x, cycle_bits(x, 8));
    printf("cycle_bits( %llu, 8) = %llu\n", x, cycle_bits(x, 8));
    printf("cycle_bits( %llu, 9) = %llu\n", x, cycle_bits(x, 9));
    printf("cycle_bits( %llu, 9) = %llu\n", x, cycle_bits(x, 9));
    printf("cycle_bits( %llu, 10) = %llu\n", x, cycle_bits(x, 10));
    printf("cycle_bits( %llu, 10) = %llu\n", x, cycle_bits(x, 10));
}

void check_reset_highestorder_strong_bit(){
    uint32_t x = 0b000111010101010;
    printf("reset_highestorder_strong_bit(%d 0b000111010101010) = %d\n", x, reset_highestorder_strong_bit(x));
    x = 0b0001;
    printf("reset_highestorder_strong_bit(%d 0b0001) = %d\n", x, reset_highestorder_strong_bit(x));
    x = 0b100111010101010;
    printf("reset_highestorder_strong_bit(%d 0b100111010101010) = %d\n", x, reset_highestorder_strong_bit(x));
    x = 0b100000000;
    printf("reset_highestorder_strong_bit(%d 0b100000000) = %d\n", x, reset_highestorder_strong_bit(x));
    x = 0b1000000001;
    printf("reset_highestorder_strong_bit(%d 0b1000000001) = %d\n", x, reset_highestorder_strong_bit(x));
    x = 0b0;
    printf("reset_highestorder_strong_bit(%d 0b0) = %d\n", x, reset_highestorder_strong_bit(x));
}

int main(int argc, char **argv) {
// call check_XXX if you want some outputs
}
