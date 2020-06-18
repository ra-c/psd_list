int :	utils.o array.o main.o item-int.o list.o
	gcc utils.o array.o main.o item-int.o list.o -o array

str :	utils.o array.o main.o item-string.o list.o
	gcc utils.o array.o main.o item-string.o list.o -o array

list.o:
	gcc -c list.c

utils.o :
	gcc -c utils.c

array.o :
	gcc -c array.c

main.o :
	gcc -c main.c

item-int.o:
	gcc -c item-int.c

item-string.o:
	gcc -c item-string.c

clean:
	rm -f *.o array.exe
