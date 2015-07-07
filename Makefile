CC=gcc
CFLAGS=-c -Wall

all: main.o resin.o hashtable.o
	$(CC) build/hashtable.o build/resin.o build/main.o -o build/resin

resin.o:
	$(CC) $(CFLAGS) resin.c -o build/resin.o

hashtable.o:
	$(CC) $(CFLAGS) hashtable.c -o build/hashtable.o

main.o:
	$(CC) $(CFLAGS) main.c -o build/main.o

clean:
	rm build/*.o build/resin