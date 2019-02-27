# Deck structure written in C
---

##`typedef int Deck_type`: Used to define the deck's type, change "int" to what you need
---

`int Deck_create(Deck*)`: Creates empty deck with size = 0, must be used
`int Deck_isempty(Deck)`: Returns if the deck is empty
`int Deck_isfull(Deck)`: Returns if the deck is full (almost never)
`int Deck_push_front(Deck, Deck_type)`: Adds an element to the front of the deck, returns 1 if failed, else 0
`int Deck_pop_front(Deck, Deck_type*)`: Returns the element through parameters from the front and removes it from the deck, undefined behavior if deck is empty
`int Deck_push_back(Deck, Deck_type)`: Adds an element to the back of the deck, returns 1 if failed, else 0
`int Deck_pop_back(Deck, Deck_type*)`: Returns the element through parameters from the front and removes it from the deck, undefined behavior if deck is empty
`int Deck_get_front(Deck, Deck_type*)`: Returns the element through parameters from the front without removing it from the deck, undefined behavior if deck is empty
`int Deck_get_back(Deck, Deck_type*)`: Returns the element through parameters from the back without removing it from the deck, undefined behavior if deck is empty
`int Deck_size(Deck)`: Returns the size of the deck (equivalent to Deck.size)
`void Deck_destroy(Deck)`: Remove all deck elements and remove the deck
