CC = gcc
AR = ar

SRCS = $(wildcard .c)

all: clean compile archive

clean:
	rm -f *.o *.a

compile:
	${CC} -Wall -c *.c

archive:
	${AR} -cvq libtlpi.a *.o

