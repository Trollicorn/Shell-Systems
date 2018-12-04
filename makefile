all: pargs.o lobster.o beatle.o
	gcc -o carapace pargs.o lobster.o beatle.o 

pargs.o: pargs.h pargs.c
	gcc -c pargs.c

lobster.o: pargs.h lobster.h lobster.c
	gcc -c lobster.c

beatle.o: pargs.h lobster.h beatle.c
	gcc -c beatle.c

run:
	./carapace
