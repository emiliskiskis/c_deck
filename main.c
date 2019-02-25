#include <stdio.h>
#include "Deck.h"

int main(){
    int z;
    Deck x;
    Deck_create(&x);
    printf("%d\n", Deck_size(x));
    scanf("%d", &z);
    for(int i = 0; i < 10000000; i++){
        if(!(i % 100000)) printf("Pushing %d to the back\n", i);
        Deck_push_back(x, i);
    }
    scanf("%d", &z);
    for(int i = 0; i < 1000000; i++){
        Deck_pop_back(x, &z);
        if(!(i % 100000)) printf("Popped %d from the back\n", z);
    }
    scanf("%d", &z);
    printf("Size was %d\n", Deck_size(x));
    Deck_destroy(x);
    scanf("%d", &z);
}
