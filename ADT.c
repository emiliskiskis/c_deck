#include <stdlib.h>
#include <stddef.h>
#include "ADT.h"
#include "tipas.h"

Deck create_deck(){
    Deck x;
    x.size = 0;
    return x;
}

int Deck_isempty(Deck *deck){
    return deck->size == 0;
}

int Deck_isfull(Deck *deck){
    deck->end->next = (Node*) malloc (sizeof(Node));
    if(deck->end->next != NULL){
        free(deck->end->next);
        deck->end->next = NULL;
        return 0;
    } else return 1;
}

int Deck_push_front(Deck *deck, _T x){
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
        deck->begin->element = x;
        oldbegin->prev = deck->begin;
        deck->begin->prev = NULL;
        deck->begin->next = oldbegin;
    }
    deck->size++;
    return 0;
}

_T Deck_pop_front(Deck *deck){
    if(deck->size > 1){
        _T x = deck->begin->element;
        deck->begin = deck->begin->next;
        free(deck->begin->prev); // Free
        deck->begin->prev = NULL;
        deck->size--;
        return x;
    } else if (deck->size == 1){
        _T x = deck->begin->element;
        free(deck->begin);
        deck->begin = NULL;
        deck->end = NULL;
        deck->size--;
        return x;
    }
}

int Deck_push_back(Deck *deck, _T x){
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
        deck->end->element = x;
        oldend->next = deck->end;
        deck->end->prev = oldend;
        deck->end->next = NULL;
    }
    deck->size++;
    return 0;
}

_T Deck_pop_back(Deck *deck){
    if(deck->size > 1){
        _T x = deck->end->element;
        deck->end = deck->end->next;
        free(deck->end->prev); // Free
        deck->end->prev = NULL;
        deck->size--;
        return x;
    } else if (deck->size == 1){
        _T x = deck->end->element;
        free(deck->end);
        deck->end = NULL;
        deck->begin = NULL;
        deck->size--;
        return x;
    }
}

_T Deck_get_front(Deck *deck){
    if(deck->size > 0){
        return deck->begin->element;
    }
}

_T Deck_get_back(Deck *deck){
    if(deck->size > 0){
        return deck->end->element;
    }
}

int Deck_size(Deck *deck){
    return deck->size;
}

void Deck_destroy(Deck *deck){
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
