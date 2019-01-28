#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>


int intNotInitialized;

int main(int argc, char const *argv[]){
	
	int intInitialized = 0;

	intNotInitialized = 42;
	intInitialized = 5;

	int* p1 = &intNotInitialized;
	int* p2 = &intInitialized;

	printf("%d\n", *p1);
	printf("%d\n", *p2);

	printf("main:         \t%p\n", (void*) &main);
	printf("globale: %d \t%p\n", intNotInitialized, (void*) &intNotInitialized);
	printf("locale:  %d \t%p\n", intInitialized, (void*) &intInitialized);

	return 0;
}

