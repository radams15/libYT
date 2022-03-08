all: swig comp

swig:
	swig -Wall -delphi -o yt.c yt.i

comp:
	gcc -shared -o _yt.so -I../include/ -I../lib/cJSON/ -fPIC ../src/main/*.c ../lib/cJSON/cJSON.c yt.c `pkg-config --libs --cflags libcurl` `python3-config --embed --libs --cflags --ldflags | xargs`

clean:
	rm -rf _yt.so yt.c yt.py __pycache__
