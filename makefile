all: main

main:
	gcc list.c item-int.c main.c -o main.out

clean:
	rm -f *.o list.out
