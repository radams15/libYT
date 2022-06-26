
OS=darwin

ifeq "${OS}" 'darwin' 
CC=gcc
CFLAGS=--std=c99
ARCH ?= -arch ppc
TARGET ?= -mmacosx-version-min=10.4 -isysroot /Developer/SDKs/MacOSX10.4u.sdk
endif

ifeq "${OS}" 'win32'
OBJ=obj
LIB=dll
CC=i686-w64-mingw32-gcc
endif

ifeq "${OS}" 'linux'
CC=gcc
OBJ=o
LIB=so
endif


CJSON_SRC=lib/cJSON/cJSON.c lib/cJSON/cJSON_Utils.c

B64_SRC=lib/librequest/lib/b64.c/buffer.c lib/librequest/lib/b64.c/decode.c lib/librequest/lib/b64.c/encode.c

REQ_SRC=lib/librequest/src/main/res.c lib/librequest/src/main/header.c lib/librequest/src/main/request_generic.c lib/librequest/src/main/backends/curl/request.c

SRCS=src/main/Config.c src/main/Channel.c src/main/Video.c src/main/Util.c src/main/Net.c src/main/Sort.c

all: build/libyt.dylib

build/libyt.so:
	mkdir -p build
	${CC} ${CFLAGS} -fPIC ${ARCH} ${TARGET} -shared ${SRCS} ${B64_SRC} ${REQ_SRC} ${CJSON_SRC} -o build/libyt.so -Ilib/librequest/include -Ilib/cJSON -Iinclude `pkg-config --libs --cflags libcurl`


build/libyt.dylib:
	mkdir -p build
	${CC} ${CFLAGS} -fPIC ${ARCH} ${TARGET} -dynamiclib ${SRCS} ${B64_SRC} ${REQ_SRC} ${CJSON_SRC} -o build/libyt.dylib -Ilib/librequest/include -Ilib/cJSON -Iinclude `pkg-config --libs --cflags libcurl`

build/test:
	        ${CC} ${CFLAGS} ${ARCH} ${TARGET} src/test/test.cpp  ${SRCS} ${B64_SRC} ${REQ_SRC} ${CJSON_SRC} -o build/libyt.dylib -Ilib/librequest/include -Ilib/cJSON -Iinclude `pkg-config --libs --cflags libcurl`

clean:
	rm -rf build
