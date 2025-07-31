/**
 * @file strext.c
 * @author Kacper Dziadek
 * @brief Implementation of strext
 * @version 0.1
 * @date 2025-07-28
 *
 * @copyright Copyright (c) 2025 Kacper Dziadek
 *
 */
#include "strext.h"
#include <string.h>

size_t utf8_len(utf8_raw_str utf8_str) {
    return strlen((char *)(utf8_str));
}

str_t str_from_utf8(utf8_raw_str utf8_str) {
    return (str_t){
        .len = utf8_len(utf8_str),
        .utf8_str = utf8_str,
    };
}

str_t str_from_char(char_raw_str raw_str) {
    return str_from_utf8(UTF8(raw_str));
}

size_t str_len(const str_t *const str) {
    return str->len;
}

utf8_raw_str str_to_utf8(const str_t *str) {
    return str->utf8_str;
}

char_raw_str str_to_char(const str_t *str) {
    return (char const *)str->utf8_str;
}

ordering_t str_cmp(const str_t *const str1, const str_t *const str2) {
    const size_t min_len = (str1->len < str2->len) ? str1->len : str2->len;
    const int result = memcmp(str1->utf8_str, str2->utf8_str, min_len);
    if (result) {
        return (result < 0) ? ordering_Less : ordering_Greater;
    }
    return (ordering_t)((str1->len > str2->len) - (str1->len < str2->len));
}

bool str_eq(const str_t *const str1, const str_t *const str2) {
    return str_cmp(str1, str2) == ordering_Equal;
}

strh_t *strh_from_utf8(const utf8_raw_str utf8_str) {
    return (strh_t *)malloc(sizeof(size_t) + sizeof(utf8_char) * utf8_len(utf8_str));
}


