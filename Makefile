default: main.out
	
%.out: %.c Deck.o Deck.h Makefile
	gcc $< Deck.o -o $@

clean:
	gcc Deck.c -c
	rm -f Deck.c main.c main.out