OS=$(shell uname -s | tr '[:upper:]' '[:lower:]')

CFLAGS=-I../lib/librequest -L../lib/librequest -std=c99

CC="gcc"

ifeq (${OS}, linux)
CC="gcc"
OBJ_EXT="so"
CFLAGS+=`pkg-config --libs --cflags libcurl`
endif

ifeq (${OS}, darwin)
#ARCH=-arch x86_64 -arch ppc
#ARCH=-arch x86_64
ARCH=-arch ppc
OBJ_EXT="dylib"

CC="gcc"
CFLAGS+=${ARCH} -lrequest
endif


INSTALL_DIR="../../MacTube/src/uk/co/therhys/YT"

comp:
	${CC} -dynamiclib -o libyt.${OBJ_EXT} -I../include/ -I../lib/cJSON/ -fPIC ../src/main/*.c ../lib/cJSON/cJSON.c ${CFLAGS}

clean:
	rm -rf *.${OBJ_EXT} yt.c *.o

install:
	ifeq (${OS}, linux)
	cp libyt.so ../../VTube/
	endif

	ifeq (${OS}, darwin)
	cp libyt.dylib ../../VTube/
	endif
