#include <stdio.h>
#include "adder.h"

int main() {
    int result = adder(2, 4);  // should give 6
    printf("The result is: %d\n", result);
    return 0;
}