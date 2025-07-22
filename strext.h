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
} string_t;

typedef struct string_mut {
    size_t len;
    char *str;
} string_mut_t;

#define string_empty(name,length) char rstr_##name[length+1] = {}; \
    name = (string_t){ .len = length, .str = rstr_##name };

void string_new(string_t *dest, char *rstr);

void string_clone(const string_t *dest, const string_t *src);


// TODO: Gotta implement
void string_concat(const string_t *dest, const string_t *src1, const string_t *src2);

// TODO: Gotta implement
string_mut_t string_mut_copy(const string_t *s);
#endif //STREXT_H
