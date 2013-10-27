linktest : main.o link1.o link2.o
	$(CC) -o linktest -Wall main.o link1.o link2.o

main.o : main.c
	$(CC) -c main.c
link1.o : link1.c
	$(CC) -c link1.c
link2.o : link2.c
	$(CC) -c link2.c

clean :
	rm linktest
	rm main.o
	rm link1.o
	rm link2.o

