//
// Created by kittech on 7/20/25.
//

#include <assert.h>
#include <stdio.h>

#include "strext.h"

void test_new(void) {
    printf("test_new() -> 0/2\n");

    string_t s;
    string_new(&s, "Hello World!");


    assert(s.len == strlen("Hello World!"));
    printf("test_new() -> 1/2\n");
    assert(strcmp(s.str, "Hello World!") == 0);
    printf("test_new() -> 2/2\n");
}

void test_copy(void) {
    printf("test_copy() -> 0/2\n");
    string_t s;
    string_t copy;
    string_new(&s, "Hello World!");
    string_empty(copy, s.len);

    string_clone(&copy, &s);

    assert(s.len == copy.len);
    printf("test_copy() -> 1/2\n");

    const int i = strcmp(s.str, copy.str);
    assert(i == 0);
    printf("test_copy() -> 2/2\n");
}

void test_concat(void) {
    // printf("test_concat() -> 0/2\n");
    //
    // const string_t s1 = string_new("Hello World!");
    // const string_t s2;
    // string_copy(&s2, &s1);
    //
    // const string_t concat = string_new_len("", s1.len + s2.len);
    // string_concat(&concat, &s1, &s2);
    // assert(concat.len == s1.len + s2.len);
    // printf("test_concat() -> 1/2\n");
    //
    // assert(strcmp(concat.str, "Hello World!Hello World!") == 0); // TODO: Memory corruption
    // printf("test_concat() -> 2/2\n");
}

int main(void) {
    test_new();
    test_copy();
    test_concat();
    return 0;
}


