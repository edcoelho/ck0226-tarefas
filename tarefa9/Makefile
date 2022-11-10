ALL: main

main: main.o listaencadeada.o
	gcc --std=c99 -pedantic-errors main.o listaencadeada.o -o main

main.o: main.c listaencadeada.h
	gcc --std=c99 -pedantic-errors -c main.c

listaencadeada.o: listaencadeada.c listaencadeada.h
	gcc --std=c99 -pedantic-errors -c listaencadeada.c

clean:
	rm -f *.o main
