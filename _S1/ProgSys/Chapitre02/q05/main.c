#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

// Les variables locales sont stockés dans la pile.

int main(int argc, char const *argv[]){
	
	int intNotInitialized;
	int intInitialized = 0;

	intNotInitialized = 42;
	intInitialized = 5;

	int* p1 = &intNotInitialized;
	int* p2 = &intInitialized;

	printf("main:         \t%p\n", (void*) &main);
	printf("globale: %d \t%p\n", intNotInitialized, (void*) &intNotInitialized);
	printf("locale:  %d \t%p\n\n", intInitialized, (void*) &intInitialized);

	*p1 = 43;
	*p2 = 6;

	printf("globale: %d \t%p\n", intNotInitialized, (void*) &intNotInitialized);
	printf("locale:  %d \t%p\n", intInitialized, (void*) &intInitialized);

	return 0;
}

