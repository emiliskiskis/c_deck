#pragma once

typedef struct Deck* Deck;

typedef int Deck_type;

int Deck_create(Deck*);
int Deck_isempty(Deck);
int Deck_isfull(Deck);
int Deck_push_front(Deck, Deck_type);
int Deck_pop_front(Deck, Deck_type*);
int Deck_push_back(Deck, Deck_type);
int Deck_pop_back(Deck, Deck_type*);
int Deck_get_front(Deck, Deck_type*);
int Deck_get_back(Deck, Deck_type*);
int Deck_size(Deck);
void Deck_destroy(Deck);
