ARCH=-arch i386 -arch ppc -arch x86_64
#ARCH=-arch x86_64
CXX=g++

all: copy comp

copy:
	cp ../cpp/libytmm.dylib .

comp:
	${CXX}  main.cpp -I../include/ -L. -o main -lytmm ${ARCH} -std=c++98
