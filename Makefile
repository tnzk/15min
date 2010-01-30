CC = gcc
DEFS = -DHAVE_CONFIG_H
LIBS = 

all: 15min.c
	$(CC) -o 15min 15min.c `sdl-config --libs --cflags`

clean:
	rm -f 15min
	rm -f *~
