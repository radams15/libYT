#!/bin/bash

rm -rf build_univ
mkdir -p build_univ

make clean

ARCH='-arch x86_64 -arch i386' TARGET='-mmacosx-version-min=10.5 -isysroot /Developer/SDKs/MacOSX10.5.sdk' make build/libyt.dylib
mv build/libyt.dylib build_univ/libyt.dylib.x86

make clean

ARCH='-arch ppc' TARGET='-mmacosx-version-min=10.3.9 -isysroot /Developer/SDKs/MacOSX10.3.9.sdk' make build/libyt.dylib

mv build/libyt.dylib build_univ/libyt.dylib.ppc

lipo -create build_univ/libyt.dylib.x86 build_univ/libyt.dylib.ppc -output build_univ/libyt.dylib