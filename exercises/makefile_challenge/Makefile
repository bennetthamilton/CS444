
CC=gcc
CFLAGS=-Wall -Wextra
LIBS=

SRCS=$(wildcard *.c)
TARGETS=$(SRCS:.c=)

.PHONY: clean pristine

clean:
	rm -f *.o

pristine: clean
	rm -f $(TARGETS)

%: %.c
	$(CC) $(CFLAGS) -o $@ $< $(LIBS)