OS=$(shell uname -s | tr '[:upper:]' '[:lower:]')

CFLAGS="-std=c99"
CXXFLAGS="-std=c++98"

CXX="g++"
CC="gcc"

ifeq (${OS}, linux)
CC="g++"
CXX="g++"
OBJ_EXT="so"
endif

ifeq (${OS}, darwin)
#ARCH=-arch i386 -arch x86_64 -arch ppc
ARCH=-arch x86_64
OBJ_EXT="dylib"

#CC="gcc-4.2"
#CXX="g++-4.2"

CFLAGS+=${ARCH}
CXXFLAGS+=${ARCH}
endif

all: clean c cpp link

c:
	mkdir -p c
	cd c && ${CC} -c ../../lib/cJSON/cJSON.c ../../src/main/*.c -I../../include/ -I../../lib/cJSON/ ${CFLAGS}

cpp:
	mkdir -p cpp
	cd cpp && ${CXX} -c ../../src/main/mm/*.cpp -I../../include/ ${CXXFLAGS}

link:
	${CXX} -shared -o libytmm.${OBJ_EXT} -fPIC -lcurl cpp/*.o c/*.o ${CXXFLAGS}

install:
	cp ../include/*.h ../../MacTube/lib/
	cp libytmm.dylib ../../MacTube/lib/

clean:
	 rm -rf c/ cpp/ libytmm.dylib
