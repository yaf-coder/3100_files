CC := gcc
CFLAGS := -g -Wall -std=c99
TARGETS := linkedlist-main

all: $(TARGETS)

linkedlist-main: linkedlist-main.c linkedlist.c
# the header file shouldn't be directly compiled
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -rf *.o $(TARGETS)
