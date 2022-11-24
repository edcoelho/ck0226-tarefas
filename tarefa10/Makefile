ALL: main

main: main.o listaencadeadadupla.o
	gcc --std=c99 -pedantic-errors main.o listaencadeadadupla.o -o main

main.o: main.c listaencadeadadupla.h
	gcc --std=c99 -pedantic-errors -c main.c

listaencadeadadupla.o: listaencadeadadupla.c listaencadeadadupla.h
	gcc --std=c99 -pedantic-errors -c listaencadeadadupla.c

clean:
	rm -f *.o main
