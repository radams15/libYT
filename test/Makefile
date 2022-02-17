ARCH=-arch i386 -arch ppc -arch x86_64
#ARCH=-arch x86_64

all:
	cp ../ffi/libyt.dylib .

	gcc main.c -I../include/ -L. -o main -lyt ${ARCH} -std=c99
