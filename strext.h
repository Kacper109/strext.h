//
// Created by kittech on 7/20/25.
//

#ifndef STREXT_H
#define STREXT_H
#include <stddef.h>
#include <stdint.h>
#include <string.h>

#define UTF8(str) (const utf8_char *const)(str)

typedef uint8_t utf8_char;

typedef struct string {
    size_t len;
    const utf8_char *const rstr;
} str_t;

typedef enum ordering {
    ordering_Less = -1,
    ordering_Equal = 0,
    ordering_Greater = 1,
} ordering_t;

size_t utf8_strlen(const utf8_char *str);
str_t str_init(const utf8_char *utf8_str);
str_t str_rinit(const char *rstr);
ordering_t str_cmp(const str_t *str1, const str_t *str2);
bool str_eq(const str_t *str1, const str_t *str2);

#endif // STREXT_H
