#include <stdio.h>

typedef enum  {LUNDI=1, MARDI, MERCREDI, JEUDI, VENDREDI, SAMEDI, DIMANCHE} jour_t;
typedef enum {JANVIER=1, FEVRIER, MARS, AVRIL, MAI, JUIN, JUILLET, AOUT, SEPTEMBRE, NOVEMBRE, DECEMBRE} mois_t;

typedef struct {
	jour_t jour;
	unsigned int jour_num;
	mois_t mois;
	unsigned int annee;
} date_t;

int main(int argc, char const *argv[]){
	
	date_t date = {LUNDI, 12, MAI, 1997};

	printf("%02d/%02d/%04d\n", date.jour_num, date.mois, date.annee);

	return 0;
}

