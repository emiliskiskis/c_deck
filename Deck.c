#include <stdlib.h>
#include <stddef.h>
#include "Deck.h"

typedef struct Node {
    Deck_type element;
    struct Node *prev, *next;
} Node;

struct Deck {
    int size;
    Node *begin, *end;
};

int Deck_create(Deck *deck){
    Deck x = (Deck) malloc (sizeof(struct Deck));
    if(x == NULL){
        return 1;
    }
    x->size = 0;
    *deck = x;
    return 0;
}

int Deck_isempty(Deck deck){
    return deck->size == 0;
}

int Deck_isfull(Deck deck){
    Node *test = (Node*) malloc (sizeof(Node));
	if(!test){
		free(test);
		return 1;
	}
	else return 0;
}

int Deck_push_front(Deck deck, Deck_type x){
    if(deck->size == 0){
        deck->begin = (Node*) malloc (sizeof(Node)); // Allocate
        if(deck->begin == NULL){
            return 1;
        }
        deck->begin->element = x;
        deck->end = deck->begin;
    } else {
        Node *oldbegin = deck->begin;
        deck->begin = (Node*) malloc (sizeof(Node)); // Allocate
        if(deck->end == NULL){
            return 1;
        }
        deck->begin->element = x;
        oldbegin->prev = deck->begin;
        deck->begin->prev = NULL;
        deck->begin->next = oldbegin;
    }
    deck->size++;
    return 0;
}

int Deck_pop_front(Deck deck, Deck_type *el){
    if(deck->size > 1){
        Deck_type x = deck->begin->element;
        deck->begin = deck->begin->next;
        free(deck->begin->prev); // Free
        deck->begin->prev = NULL;
        deck->size--;
        *el = x;
        return 0;
    } else if (deck->size == 1){
        Deck_type x = deck->begin->element;
        free(deck->begin);
        deck->begin = NULL;
        deck->end = NULL;
        deck->size--;
        *el = x;
        return 0;
    } else return 1;
}

int Deck_push_back(Deck deck, Deck_type x){
    if(deck->size == 0){
        deck->end = (Node*) malloc (sizeof(Node)); // Allocate
        if(deck->end == NULL){
            return 1;
        }
        deck->end->element = x;
        deck->begin = deck->end;
    } else {
        Node *oldend = deck->end;
        deck->end = (Node*) malloc (sizeof(Node)); // Allocate
        if(deck->end == NULL){
            return 1;
        }
        deck->end->element = x;
        oldend->next = deck->end;
        deck->end->prev = oldend;
        deck->end->next = NULL;
    }
    deck->size++;
    return 0;
}

int Deck_pop_back(Deck deck, Deck_type *el){
    if(deck->size > 1){
        Deck_type x = deck->end->element;
        deck->end = deck->end->prev;
        free(deck->end->next); // Free
        deck->end->next = NULL;
        deck->size--;
        *el = x;
        return 0;
    } else if (deck->size == 1){
        Deck_type x = deck->end->element;
        free(deck->end);
        deck->end = NULL;
        deck->begin = NULL;
        deck->size--;
        *el = x;
        return 0;
    }
    else return 1;
}

int Deck_get_front(Deck deck, Deck_type *el){
    if(deck->size > 0){
        *el = deck->begin->element;
        return 0;
    }
    else return 1;
}

int Deck_get_back(Deck deck, Deck_type *el){
    if(deck->size > 0){
        *el = deck->end->element;
        return 0;
    }
    else return 1;
}

int Deck_size(Deck deck){
    return deck->size;
}

void Deck_destroy(Deck deck){
    if(deck->size > 0){
        Node *w = deck->begin;
        for(int i = 0; i < (deck->size)-1; i++){
            w = w->next;
            free(w->prev);
        }
        free(w);
    }
    free(deck);
}
