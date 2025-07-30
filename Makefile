CFLAGS = -std=c23 -g3 -Wall -Wextra -Werror -fsanitize=address,undefined -fsanitize-trap
CC = /usr/bin/clang
AR = /usr/bin/ar
BUILD = build

all: build test clean

test: build test.c lib
	$(CC) test.c -L${BUILD} -lstrext -o ${BUILD}/test.o ${CFLAGS}
	${BUILD}/test.o

lib: build strext.c strext.h
	$(CC) -c strext.c -o ${BUILD}/strext.o -fPIC ${CFLAGS}
	$(AR) rc ${BUILD}/libstrext.a ${BUILD}/strext.o


build:
	mkdir ${BUILD}

clean: 
	rm -r ${BUILD}
