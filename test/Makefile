ARCH=-arch i386 -arch ppc -arch x86_64
#ARCH=-arch x86_64

all:
	cp ../cpp/libytmm.dylib .

	g++ main.cpp -I../include/ -L. -o main -lytmm ${ARCH} -std=c++98
