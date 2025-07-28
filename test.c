#include "strext.h"
#include <stdio.h>

int main(void) {
    str_t example_string = str_new("Hello world!");
    str_t empty_string = str_new("H2332423o sworld!");
    printf("\"%s\" %zu\n", empty_string.str, empty_string.len);
    printf("\"%s\" %zu\n", example_string.str, example_string.len);

    return 0;
}