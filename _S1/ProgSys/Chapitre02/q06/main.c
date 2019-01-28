#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#define TAILLE 10

// Sizeof(tab) correspond a la taille en octets d'un tableau

int main(int argc, char const *argv[]){
	
	int tab[TAILLE];

	printf("Nb cases:          %d\n", TAILLE);
	printf("Taille d'un int:   %d octets\n", (int) sizeof(int));
	printf("Sizeof(tab):       %d\n", (int) sizeof(tab));

	return 0;
}

