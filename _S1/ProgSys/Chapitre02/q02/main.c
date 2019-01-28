#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

/*
	Enlever le flag "-pedantic"
	pour que ça marche.
*/

// La variable globale est stocké dans le BSS segment
// La variable locale est stocké dans la pile

int intNotInitialized;

int main(int argc, char const *argv[]){
	
	int intInitialized = 0;

	intNotInitialized = 42;
	intInitialized = 5;

	printf("main:         \t%p\n", (void*) &main);
	printf("globale: %d \t%p\n", intNotInitialized, (void*) &intNotInitialized);
	printf("locale:  %d \t%p\n", intInitialized, (void*) &intInitialized);

	return 0;

}

