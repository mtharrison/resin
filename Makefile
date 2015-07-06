CC=gcc
CFLAGS=-c -Wall

all: example.o resin.o
	$(CC) build/resin.o build/example.o -o build/resin

resin.o:
	$(CC) $(CFLAGS) resin.c -o build/resin.o

example.o:
	$(CC) $(CFLAGS) example.c -o build/example.o

clean:
	rm build/*.o build/resin