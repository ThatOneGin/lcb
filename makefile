cc = gcc
cflags = -lncurses -I/usr/include/lua -llua -lm -lncurses -fPIC

all:
	$(cc) -shared -o lcb.so lcb.c $(cflags)