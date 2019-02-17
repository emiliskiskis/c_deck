#include <stdio.h>
#include "ADT.h"

int main(){
    Deck x = create_deck();
    printf("%d\n", Deck_size(&x));
    printf("%d\n", Deck_isempty(&x));
    Deck_push_front(&x, 5165);
    printf("%d\n%d\n%d\n", Deck_isempty(&x), Deck_get_front(&x), Deck_get_back(&x));
    printf("%d\n", Deck_isempty(&x));
    printf("%d\n", Deck_pop_front(&x));
    printf("%d\n", Deck_push_back(&x, 200));
    Deck_destroy(&x);
}
