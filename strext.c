//
// Created by kittech on 7/20/25.
//

#include "strext.h"

#include <assert.h>
#include <stdlib.h>

void string_new(string_t *dest, char *rstr) {
    *dest = (string_t){
        .len = strlen(rstr),
        .str = rstr
    };
}

void string_clone(const string_t *dest, const string_t *src) {
    assert(dest->len >= src->len);
    memcpy(dest->str, src->str, src->len);
    // strncpy(dest->str, src->str, src->len);
}



