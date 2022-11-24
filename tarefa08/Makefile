ALL: main

main: main.o agenda.o
	gcc --std=c99 -pedantic-errors main.o agenda.o -o main

main.o: main.c agenda.h
	gcc --std=c99 -pedantic-errors -c main.c

agenda.o: agenda.c agenda.h
	gcc --std=c99 -pedantic-errors -c agenda.c

clean:
	rm -f *.o main
