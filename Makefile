CC = gcc
CFLAGS = -Wall `sdl-config --libs --cflags`

15min: 15min.o render.o 
	$(CC) $(CFLAGS) -lGL -o 15min 15min.o render.o

15min.o: 15min.c
	$(CC) $(CFLAGS) -c 15min.c

render.o: render.c
	$(CC) $(CFLAGS) -c -lGL render.c

.PHONY: clean
clean:
	rm -f 15min 15min.o render.o
