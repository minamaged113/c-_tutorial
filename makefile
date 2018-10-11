# this makefile was made using the following tutorial
# http://www.cs.colby.edu/maxwell/courses/tutorials/maketutor/
CC=g++
CFLAGS=-I.
DEPS=main_usage.h 

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

test:	test.o main_usage.o
	$(CC) -o prog.out test.o main_usage.o