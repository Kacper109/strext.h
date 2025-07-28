//
// Created by kittech on 7/20/25.
//

#ifndef STREXT_H
#define STREXT_H
#include <stddef.h>
#include <string.h>

typedef struct string {
    size_t len;
    char *str;
} str_t;

str_t str_new(char *rstr);
#endif // STREXT_H
