CC = gcc
CFLAGS = -g
DEBUG_FLAGS = -Wall -g -O0
RELEASE_FLAGS = -O3

.PHONY: clean

all: debug release

debug: bt_debug

bt_debug: binary_tree.o main.o
	$(CC) $(DEBUG_FLAGS) -o $@ $^

release: bt

bt: binary_tree.o main.o
	$(CC) $(RELEASE_FLAGS) -o $@ $^

clean:
	rm -rf bt bt_debug *.o
