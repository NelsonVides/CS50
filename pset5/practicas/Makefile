# Makefile for data-structures

# compiler to use
CC = clang
# flags to pass compiler
CFLAGS = -ggdb3 -O0 -Qunused-arguments -std=c11 -Wall -Werror
# name for executable
EXE = #speller
# space-separated list of header files
HDRS = #dictionary.h
# space-separated list of libraries, if any,
# each of which should be prefixed with -l
LIBS = #-lcs50 -lm
# space-separated list of source files
SRCS = #speller.c dictionary.c
# automatically generated list of object files
OBJS = $(SRCS:.c=.o)
# default target
$(EXE): $(OBJS) $(HDRS) Makefile
	$(CC) $(CFLAGS) -o $@ $(OBJS) $(LIBS)
# dependencies 
$(OBJS): $(HDRS) Makefile
# housekeeping
clean:
	rm -f core $(EXE) *.o
#	rm -f *.o a.out core all	

all: sllists

sllists: sllists.c
	$(CC) $(CFLAGS) -o $@ sllists.c $(LIBS)

dllists: dllists.c
	$(CC) $(CFLAGS) -o $@ dllists.c $(LIBS)

tries: tries.c tries.h
	$(CC) $(CFLAGS) -o $@ tries.c $(LIBS)
#generate: generate.c
#	clang -ggdb3 -O0 -std=c11 -Wall -Werror -o generate generate.c
