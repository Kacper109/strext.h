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
#include <string.h>

/**
 * @brief Casts normal string to utf8 string
 *
 */
#define UTF8(str) (const utf8_char *const)(str)

typedef uint8_t utf8_char;
typedef uint8_t const *utf8_raw_str;
typedef char const *char_raw_str;

typedef struct {
    const size_t len;
    const utf8_raw_str utf8_str;
} str_t;

typedef enum ordering {
    ordering_Less = -1,
    ordering_Equal = 0,
    ordering_Greater = 1,
} ordering_t;

/**
 * @brief Length of utf8 (unsigned char) string
 *
 * @param str Unsigned char
 * @return size_t Length
 */
size_t utf8_len(const utf8_char *utf8_str);

/**
 * @brief Creates new sized immutable string
 *
 * @param utf8_str Unsigned char
 * @return str_t Sized immutable string
 */
str_t str_from_utf8(const utf8_char *utf8_str);

/**
 * @brief Creates new sized immutable string
 *
 * @param rstr Signed C char
 * @return str_t Sized immutable string
 */
str_t str_from_char(const char *raw_str);

/**
 * @brief Compares two strings
 *
 * @param str1 String to be compared against
 * @param str2 String to compare against str1
 * @return ordering_t Ordering of comperation
 */
ordering_t str_cmp(const str_t *str1, const str_t *str2);

/**
 * @brief Equality of two strings
 *
 * @param str1
 * @param str2
 * @return true Strings are equal
 * @return false Strings are not equal
 */
bool str_eq(const str_t *str1, const str_t *str2);

size_t str_len(const str_t *str);

utf8_raw_str str_to_utf8(const str_t *str);
char_raw_str str_to_char(const str_t *str);

#endif // STREXT_H
