all: main debug

main:
	gcc list.c item-int.c main.c -o main.out

debug:
	gcc -g list.c item-int.c main.c -o debug_main.out -Werror -Wall

clean:
	rm -f *.o list.out
