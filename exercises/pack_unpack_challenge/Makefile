CC=gcc
CCOPTS=-Wall -Wextra
LIBS=

SRCS=$(wildcard *.c)
TARGETS=$(SRCS:.c=)

.PHONY: all clean

all: main

main: main.o pack.o
	$(CC) $(CCOPTS) -o $@ $< $(LIBS)

main.o: main.c
	$(CC) $(CCOPTS) -c $< -o $@

pack.o: pack.c pack.h
	$(CC) $(CCOPTS) -c $< -o $@

clean:
	rm -f *.o $(TARGETS)

%: %.c
	$(CC) $(CCOPTS) -o $@ $< $(LIBS)
    
