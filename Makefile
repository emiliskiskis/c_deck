default: main.out
	
%.out: %.c Deck.o Deck.h Makefile
	gcc $< Deck.o -o $@
