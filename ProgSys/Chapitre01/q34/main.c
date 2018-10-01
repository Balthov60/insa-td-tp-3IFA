#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

typedef enum {
	S1_MAJORITAIRE_UNI, 
	S1_MAJORITAIRE_PLURI,
	S1_PROPORTIONNEL, 
	S1_MIXTE
} scrutin1_t;

typedef enum {
	S2_MAJORITAIRE_UNI = 2, 
	S2_MAJORITAIRE_PLURI = 8,
	S2_PROPORTIONNEL = 42, 
	S2_MIXTE = 12
} scrutin2_t;

typedef enum {
	S3_MAJORITAIRE_UNI = 4, 
	S3_MAJORITAIRE_PLURI,
	S3_PROPORTIONNEL, 
	S3_MIXTE
} scrutin3_t;

int main(){
	printf("\n\ntypedef enum {MAJORITAIRE_UNI, MAJORITAIRE_PLURI, PROPORTIONNEL, MIXTE} scrutin_t;\n");
	printf("   MAJORITAIRE: %d\n", S1_MAJORITAIRE_UNI);
	printf("   MAJORITAIRE_PLURI: %d\n", S1_MAJORITAIRE_PLURI);
	printf("   PROPORTIONNEL: %d\n", S1_PROPORTIONNEL);
	printf("   MIXTE: %d\n", S1_MIXTE);

	printf("\n\ntypedef enum {MAJORITAIRE_UNI = 2, MAJORITAIRE_PLURI = 8, PROPORTIONNEL = 42, MIXTE = 12} scrutin_t;\n");
	printf("   MAJORITAIRE: %d\n", S2_MAJORITAIRE_UNI);
	printf("   MAJORITAIRE_PLURI: %d\n", S2_MAJORITAIRE_PLURI);
	printf("   PROPORTIONNEL: %d\n", S2_PROPORTIONNEL);
	printf("   MIXTE: %d\n", S2_MIXTE);

	printf("\n\ntypedef enum {MAJORITAIRE_UNI = 4, MAJORITAIRE_PLURI, PROPORTIONNEL, MIXTE} scrutin_t;\n");
	printf("   MAJORITAIRE: %d\n", S3_MAJORITAIRE_UNI);
	printf("   MAJORITAIRE_PLURI: %d\n", S3_MAJORITAIRE_PLURI);
	printf("   PROPORTIONNEL: %d\n", S3_PROPORTIONNEL);
	printf("   MIXTE: %d\n", S3_MIXTE);
}