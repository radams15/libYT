
CC=gcc
CFLAGS='--std=c99'
ARCH ?= -arch ppc
TARGET ?= -mmacosx-version-min=10.4 -isysroot /Developer/SDKs/MacOSX10.4u.sdk


SRCS=src/main/Config.c src/main/Channel.c src/main/Video.c src/main/Util.c src/main/Net.c lib/cJSON/cJSON.c lib/cJSON/cJSON_Utils.c

all: build/libyt.dylib

build/libyt.dylib:
	mkdir -p build
	${CC} ${CFLAGS} -fPIC ${ARCH} ${TARGET} -dynamiclib ${SRCS} -o build/libyt.dylib -Llib/librequest -lrequest -Ilib/librequest -Ilib/cJSON -Iinclude

clean:
	rm -rf build