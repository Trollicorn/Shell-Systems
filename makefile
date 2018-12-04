all: pargs.o lobster.o beetle.o
	gcc -o carapace pargs.o lobster.o beetle.o 

pargs.o: pargs.h pargs.c
	gcc -c pargs.c

lobster.o: pargs.h lobster.h lobster.c
	gcc -c lobster.c

beatle.o: pargs.h lobster.h beetle.c
	gcc -c beetle.c

run:
	./carapace
