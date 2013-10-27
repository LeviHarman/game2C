linktest : main.o link1.o link2.o
	$(CC) -o linktest -Wall main.o link1.o link2.o -L/usr/Allegro/lib/ -lallegro -lallegro_font -lallegro_ttf

main.o : main.c
	$(CC) -c main.c -I/usr/Allegro/include/
link1.o : link1.c
	$(CC) -c link1.c
link2.o : link2.c
	$(CC) -c link2.c

clean :
	rm linktest
	rm main.o
	rm link1.o
	rm link2.o

