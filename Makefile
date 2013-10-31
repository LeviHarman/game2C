game2 : main.o link1.o link2.o draw.o
	$(CC) -o game2 -Wall main.o link1.o link2.o draw.o -L/usr/Allegro/lib/ -lallegro -lallegro_font -lallegro_ttf -lallegro_primitives

main.o : main.c
	$(CC) -c main.c -I/usr/Allegro/include/
link1.o : link1.c
	$(CC) -c link1.c
link2.o : link2.c
	$(CC) -c link2.c
draw.o : draw.c
	$(CC) -c draw.c

clean :
	rm -f game2
	rm -f main.o
	rm -f link1.o
	rm -f link2.o
	rm -f draw.o

