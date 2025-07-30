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

size_t utf8_strlen(const utf8_char *const utf8_str) {
    return strlen((const char *)(utf8_str));
}

str_t str_init(const utf8_char *const utf8_str) {
    return (str_t){
        .len = utf8_strlen(utf8_str),
        .utf8_str = utf8_str,
    };
}

str_t str_raw_init(const char *const raw_str) {
    return str_init(UTF8(raw_str));
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