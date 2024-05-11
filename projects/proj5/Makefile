
CCOPTS=-Wall -Wextra
CC=gcc

.PHONY: clean pristine test

all: testfs

testfs: testfs.o libvvsfs.a
	$(CC) $(CCOPTS) $^ -o $@

testfs.o: testfs.c
	$(CC) $(CCOPTS) -c $< -o $@

image.o: image.c image.h
	$(CC) $(CCOPTS) -c $< -o $@

block.o: block.c block.h
	$(CC) $(CCOPTS) -c $< -o $@

libvvsfs.a: block.o image.o
	ar rcs $@ $^

clean:
	rm -f *.o 

pristine: clean
	rm -f testfs *.a

test: testfs.c
	@gcc $(CCOPTS) -DCTEST_ENABLE -o testfs $^
	@./testfs
	@rm -f testfs