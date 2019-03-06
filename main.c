#include <stdio.h>
#include "Deck.h"

void myStressTest(){
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

void jonasStressTest(){
	Deck test;
	Deck_create(&test);
	int temp;
	for(int i = 0; i < 10000; i++){
		for(int j = 0; j < 10000; j++){
			if(Deck_push_back(test, (i+1)*(j+1))){
				printf("Idedant ivyko klaida\n");
				return;			
			}
		}
		for(int j = 0; j < 10000; j++){
			int x;
			Deck_pop_back(test, &x);
		}
	}
	printf("Size: %d\n", Deck_size(test));
}

int main(){
    Deck x;
    int temp;
    Deck_create(&x);
    printf("%d\n", Deck_isfull(x));
}
