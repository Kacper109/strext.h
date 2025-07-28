//
// Created by kittech on 7/20/25.
//

#include "strext.h"

#include <assert.h>

str_t str_new(char *rstr) {
    return (str_t){
        .len = strlen(rstr),
        .str = rstr
    };
}
