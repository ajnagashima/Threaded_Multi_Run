CC=gcc
CFLAGS=-pthread.

tmr: threadedMultiRun.c
	`$(CC) -o tmr threadedMultiRun.c $(CFLAGS)
