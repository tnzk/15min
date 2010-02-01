CC = gcc
CFLAGS = -Wall -llua -lglut

15min: 15min.o render.o 
	$(CC) $(CFLAGS) -o 15min 15min.o render.o `sdl-config --libs --cflags`

15min.o: 15min.c
	$(CC) -c -Wall 15min.c `sdl-config --libs --cflags`

render.o: render.c
	$(CC) -c -Wall render.c `sdl-config --libs --cflags`

.PHONY: clean
clean:
	rm -f 15min 15min.o render.o
