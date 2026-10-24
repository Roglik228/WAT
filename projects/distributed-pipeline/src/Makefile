CFLAGS = -O2 -Wall
LDFLAGS = -s
CC = gcc
SHELL = /bin/sh

all: proces4

proces4: proces4_c_udp_hex.c
	$(CC) $(CFLAGS) proces4_c_udp_hex.c -o proces4

clean:
	rm -f proces4 *.o
