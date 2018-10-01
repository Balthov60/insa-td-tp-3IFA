#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

typedef enum {
	LUNDI = 1,
	MARDI,
	MERCREDI,
	JEUDI,
	VENDREDI,
	SAMEDI,
	DIMANCHE
} jour_t;

int main(){
	printf("\n\ntypedef enum {LUNDI = 1, MARDI, MERCREDI, JEUDI, VENDREDI, SAMEDI, DIMANCHE} jour_t;\n");
	printf("   LUNDI: %d\n", LUNDI);
	printf("   MARDI: %d\n", MARDI);
	printf("   MERCREDI: %d\n", MERCREDI);
	printf("   JEUDI: %d\n", JEUDI);
	printf("   VENDREDI: %d\n", VENDREDI);
	printf("   SAMEDI: %d\n", SAMEDI);
	printf("   DIMANCHE: %d\n", DIMANCHE);
}

