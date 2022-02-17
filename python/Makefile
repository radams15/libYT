all: swig comp

swig:
	swig -Wall -python -o yt.c yt.i

comp:
	gcc -shared -o _yt.so -I../include/ -I../lib/cJSON/ -fPIC ../src/main/*.c ../lib/cJSON/cJSON.c yt.c `pkg-config --libs --cflags libxml-2.0 libcurl python3`

clean:
	rm -rf _yt.so yt.c yt.py __pycache__