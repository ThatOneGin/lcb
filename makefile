cc = gcc
cflags = -lncurses -I/usr/include/lua -llua -lm -lncurses -fPIC

all:
	$(cc) -shared -o lcblib.so lcblib.c $(cflags)