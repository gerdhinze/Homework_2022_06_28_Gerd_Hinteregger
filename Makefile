CFLAGS=-std=c99 -g -Wall  
CC=gcc
UNITY=unity

all: test

init:
	mkdir -p build

unity.o: $(UNITY)/unity.c $(UNITY)/unity.h
	$(CC) $(CFLAGS) -c $(UNITY)/unity.c -o build/unity.o

sortalgs.o: sortalgs.h sortalgs.c
	$(CC) $(CFLAGS) -c sortalgs.c -o build/sortalgs.o

utils.o: utils.h utils.c
	$(CC) $(CFLAGS) -c utils.c -o build/utils.o

test.o: test.c
	$(CC) $(CFLAGS) -I $(UNITY) -c test.c -o build/test.o

test: init unity.o sortalgs.o test.o
	$(CC) $(CFLAGS) build/unity.o build/sortalgs.o build/test.o -o build/test
	build/test

clean:
	rm -rf build/
