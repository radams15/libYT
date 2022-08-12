OS=$(shell uname -s | tr '[:upper:]' '[:lower:]')

JAVA_HOME=""
CFLAGS="-std=c99"

CC="gcc"

ifeq (${OS}, linux)
CC="gcc"
OBJ_EXT="so"
#JAVA_HOME="/usr/lib/jvm/java-1.8.0/"
JAVA_HOME="/usr/lib/jvm/java-1.8.0-openjdk-amd64/"
#JAVA_HOME="/usr/lib/jvm/java-1.6.0-openjdk.x86_64/"
CFLAGS+=`pkg-config --libs --cflags libcurl`
endif

ifeq (${OS}, darwin)
#ARCH=-arch i386 -arch x86_64 -arch ppc
ARCH=-arch ppc
OBJ_EXT="dylib"

CC="gcc-4.2"
JAVA_HOME="/System/Library/Java/JavaVirtualMachines/1.6.0.jdk/Contents/Home"
CFLAGS+=${ARCH} -framework libcurl -Wl,-F/System/Library/Frameworks
endif


INSTALL_DIR="../../java/JYT/src/main/java/uk/co/therhys/LibYT"
LIB_INSTALL_DIR="../../java/JYT/src/main/resources/"

all: swig comp

swig:
	swig -Wall -java -noproxy -package uk.co.therhys.LibYT -o yt.c yt.i
	find . -type f -name '*.java' -exec sed -i 's/@SuppressWarnings(".*")//gm' {} \;

comp:
	${CC} -shared -o yt.${OBJ_EXT} -I../include/ -I../lib/cJSON/ -fPIC ../src/main/*.c ../lib/cJSON/cJSON.c ../lib/librequest/lib/b64.c/buffer.c ../lib/librequest/lib/b64.c/encode.c ../lib/librequest/lib/b64.c/decode.c -I../lib/librequest/lib/b64.c ../lib/librequest/src/main/res.c ../lib/librequest/src/main/header.c ../lib/librequest/src/main/request_generic.c ../lib/librequest/src/main/backends/curl/request.c -I../lib/librequest/include yt.c -I${JAVA_HOME}/include -I${JAVA_HOME}/include/${OS} ${CFLAGS}

clean:
	rm -rf *.${OBJ_EXT} yt.c *.o *.java

install:
	rm -f ${INSTALL_DIR}/*
	mkdir -p ${INSTALL_DIR}
	cp *.java ${INSTALL_DIR}
	cp *.${OBJ_EXT} ${LIB_INSTALL_DIR}
