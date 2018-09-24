CC = gcc
CFLAGS = -Wall -Werror -g -lm -fsanitize=address

all: simpleCSVsorter

simpleCSVsorter: simpleCSVsorter.c simpleCSVsorter.h
	$(CC) $(CFLAGS) -o simpleCSVsorter simpleCSVsorter.c

clean:
	rm -f simpleCSVsorter
