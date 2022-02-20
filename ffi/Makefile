OS=$(shell uname -s | tr '[:upper:]' '[:lower:]')

CFLAGS="-std=c99"

CC="gcc"

ifeq (${OS}, linux)
CC="gcc"
OBJ_EXT="so"
CFLAGS+=`pkg-config --libs --cflags libcurl`
endif

ifeq (${OS}, darwin)
#ARCH=-arch i386 -arch x86_64 -arch ppc
ARCH=-arch x86_64
OBJ_EXT="dylib"

#CC="gcc-4.2"
CFLAGS+=${ARCH} `pkg-config --libs --cflags libcurl`
endif


INSTALL_DIR="../../MacTube/src/uk/co/therhys/YT"

comp:
	${CC} -shared -o libyt.${OBJ_EXT} -I../include/ -I../lib/cJSON/ -fPIC ../src/main/*.c ../lib/cJSON/cJSON.c ${CFLAGS}

clean:
	rm -rf *.${OBJ_EXT} yt.c *.o

install:
	echo ''
