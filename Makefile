default: main.out

%.out: %.c Deck.c Deck.h Makefile
	gcc $< Deck.c -o $@
	
%.out: %.c Deck.o Deck.h Makefile
	gcc $< Deck.o -o $@
	
Deck.o: Deck.c Deck.h
	gcc -c Deck.c -o Deck.o
