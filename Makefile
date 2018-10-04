CC = gcc
CFLAGS = -Wall -Werror -g -lm -fsanitize=address

all: simpleCSVsorter

simpleCSVsorter: simpleCSVsorter.c simpleCSVsorter.h
	$(CC) $(CFLAGS) -o simpleCSVsorter simpleCSVsorter.c mergesort.c

simpleCSVsorter.o: simpleCSVsorter.c simpleCSVsorter.h
	$(CC) -c simpleCSVsorter.c

mergesort.o: mergesort.c mergesort.h
	$(CC) -c mergesort.c

clean:
	rm -f simpleCSVsorter *.o
