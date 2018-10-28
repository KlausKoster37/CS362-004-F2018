# makefile for random quiz
# Author: Klaus Koster
# Due Date: 10/28/2018
# CS 362, Fall 2018

# copied based items (all, flags, clean) and modified from dominion makefile

CFLAGS= -Wall -fpic -coverage -lm -std=c99

testme: testme.c
	gcc -o testme testme.c $(CFLAGS)

all: testme

clean:
	rm -f *.o *.gcov *.gcda *.gcno *.so *.out testme