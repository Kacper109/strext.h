#include "strext.h"
#include <assert.h>
#include <stdio.h>

void test_cmp() {
    printf("-- Test: Compare String 0/3 --\n");

    str_t str1 = str_rinit("Hello World!");
    str_t str2 = str_rinit("Hello World");
    str_t str3 = str_rinit("");
    str_t str4 = str_rinit("Hello World!");

    assert(str_cmp(&str1, &str2) == ordering_Greater);
    printf("-- Test: Compare String 1/3 --\n");

    assert(str_cmp(&str3, &str1) == ordering_Less);
    printf("-- Test: Compare String 2/3 --\n");

    assert(str_cmp(&str1, &str4) == ordering_Equal);
    printf("-- Test: Compare String 3/3 --\n");
}

void test_eq() {
    printf("-- Test: Compare Equal 0/3 --\n");

    str_t str1 = str_rinit("Hello World!");
    str_t str2 = str_rinit("Hello World");
    str_t str3 = str_rinit("");
    str_t str4 = str_rinit("Hello World!");

    assert(str_eq(&str1, &str2) == false);
    printf("-- Test: Compare Equal 1/3 --\n");

    assert(str_eq(&str3, &str1) == false);
    printf("-- Test: Compare Equal 2/3 --\n");

    assert(str_eq(&str1, &str4) == true);
    printf("-- Test: Compare Equal 3/3 --\n");
}

int main(void) {
    test_cmp();
    test_eq();
    return 0;
}