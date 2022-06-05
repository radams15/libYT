#ARCH=-arch i386 -arch ppc -arch x86_64
#ARCH=-arch x86_64
ARCH=
CXX=g++

all: copy comp

copy:
	cp ../ffi/libyt.dylib .

comp:
	${CXX}  main.cpp -I../include/ -L. -o main -lyt ${ARCH} -std=c++98
