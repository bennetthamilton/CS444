#include "free.h"

void set_free(unsigned char *block, int num, int set) {
    int byte_i = num / 8;
    int bit_i = num % 8;
    block[byte_i] = (block[byte_i] & ~(1 << bit_i)) | (set << bit_i);
}

int find_free(unsigned char *block) {
    return 0;
}