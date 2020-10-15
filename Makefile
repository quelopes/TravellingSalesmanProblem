CV: main.o matriz.o AGs.o
	g++ -o CV main.o matriz.o AGs.o
matriz.o: matriz.c caixeiroViajante_TAD.h
	g++ -c matriz.c
AGs.o: AGs.c caixeiroViajante_TAD.h
	g++ -c AGs.c
main.o: main.c caixeiroViajante_TAD.h
	g++ -c main.c
