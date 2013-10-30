linktest : main.o link1.o link2.o
	$(CC) -o game2 -Wall main.o link1.o link2.o -L/usr/Allegro/lib/ -lallegro -lallegro_font -lallegro_ttf

main.o : main.c
	$(CC) -c main.c -I/usr/Allegro/include/
link1.o : link1.c
	$(CC) -c link1.c
link2.o : link2.c
	$(CC) -c link2.c

clean :
	rm -f linktest
	rm -f main.o
	rm -f link1.o
	rm -f link2.o

