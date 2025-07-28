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

#include <assert.h>

/*
BSD implementation
https://cvsweb.openbsd.org/cgi-bin/cvsweb/src/lib/libc/string/strlen.c?rev=1.9
*/
size_t utf8_strlen(const utf8_char *const str) {
    const utf8_char *s;

    for (s = str; *s; ++s)
        ;
    return (s - str);
}

str_t str_init(const utf8_char *const utf8_str) {
    return (str_t){
        .len = utf8_strlen(utf8_str),
        .rstr = utf8_str,
    };
}

str_t str_rinit(const char *const rstr) {
    return str_init(UTF8(rstr));
}

ordering_t str_cmp(const str_t *const str1, const str_t *const str2) {
    const size_t min_len = (str1->len < str2->len) ? str1->len : str2->len;
    const int result = memcmp(str1->rstr, str2->rstr, min_len);
    if (result != 0) {
        return (result < 0) ? ordering_Less : ordering_Greater;
    }
    return (str1->len > str2->len) - (str1->len < str2->len);
}

bool str_eq(const str_t *const str1, const str_t *const str2) {
    return str_cmp(str1, str2) == ordering_Equal;
}