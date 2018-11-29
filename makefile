all: lobster.o pargs.o
	gcc -o lobster lobster.o pargs.o

lobster.o: pargs.h lobster.c
	gcc -c lobster.c

pargs.o: pargs.h pargs.c
	gcc -c pargs.c

run:
	./lobster
