main: individu.o population.o main.o individu.h population.h parametre.h
	gcc -o main individu.o population.o main.o -lm
individu.o: individu.c individu.h parametre.h
	gcc -o individu.o -c individu.c -lm
main.o: main.c individu.h individu.o population.h population.o parametre.h
	gcc -o main.o -c main.c -lm
population.o: population.c population.h parametre.h
	gcc -o population.o -c population.c -lm

