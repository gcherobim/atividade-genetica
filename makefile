exec: funcoes.o main.o
	gcc main.o funcoes.o -o exec -std=c99 -pedantic-errors -Wall -lm

funcoes.o:
	gcc -c funcoes.c -o funcoes.o

main.o:
	gcc -c main.c -o main.o

clean:
	rm *.o exec

run:
	./exec
