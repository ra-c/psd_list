all: main

main:
	gcc list.c item-int.c main.c

clean:
	rm -f *.o list.out
