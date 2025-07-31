/**
 * @file strext.h
 * @author Kacper Dziadek
 * @brief Definition of strext
 * @version 0.1
 * @date 2025-07-28
 *
 * @copyright Copyright (c) 2025 Kacper Dziadek
 *
 */
#ifndef STREXT_H
#define STREXT_H

#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#define UTF8(str) (const utf8_char *const)(str)

typedef uint8_t utf8_char;
typedef uint8_t const *utf8_raw_str;
typedef char const *char_raw_str;

typedef struct {
    const size_t len;
    const utf8_raw_str utf8_str;

} str_t;

typedef struct {
    size_t len;
    const utf8_raw_str utf8_str;
} str_obj_t;

typedef enum ordering {
    ordering_Less = -1,
    ordering_Equal = 0,
    ordering_Greater = 1,
} ordering_t;

#define str_from(str) _Generic(  \
    str,                         \
    utf8_raw_str: str_from_utf8, \
    char *: str_from_char)(str)

#define str_obj_from(str) _Generic(  \
    str,                         \
    utf8_raw_str: str_obj_from_utf8, \
    char *: str_obj_from_char)(str)

str_t str_from_utf8(utf8_raw_str utf8_str);

str_t str_from_char(char_raw_str raw_str);

size_t utf8_len(utf8_raw_str utf8_str);

size_t str_len(const str_t *str);

utf8_raw_str str_to_utf8(const str_t *str);

char_raw_str str_to_char(const str_t *str);

ordering_t str_cmp(const str_t *str1, const str_t *str2);

bool str_eq(const str_t *str1, const str_t *str2);

str_obj_t str_obj_from_utf8(utf8_raw_str utf8_str);

str_obj_t str_obj_from_char(char_raw_str char_str);

#endif // STREXT_H
