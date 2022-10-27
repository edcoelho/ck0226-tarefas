ALL: main

main: main.o agenda.o
	gcc main.o agenda.o -o main

main.o: main.c agenda.h
	gcc -c main.c

agenda.o: agenda.c agenda.h
	gcc -c agenda.c

clean:
	rm -f *.o main
