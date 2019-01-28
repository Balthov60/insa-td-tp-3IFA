#include <stdio.h>

typedef struct {
	enum {LUNDI=1, MARDI, MERCREDI, JEUDI, VENDREDI, SAMEDI, DIMANCHE} jour_num;
	unsigned int jour;
	enum {JANVIER=1, FEVRIER, MARS, AVRIL, MAI, JUIN, JUILLET, AOUT, SEPTEMBRE, NOVEMBRE, DECEMBRE} mois;
	unsigned int annee;
} date_t;

typedef struct{
	int id;
	date_t dateDeNaissance;
	char boissonPref[20];
} etudiant_t;

int main(int argc, char const *argv[]){
	
	etudiant_t etudiants[3] = {
		{
			666,
			{LUNDI, 12, MAI, 1997},
			"MOJITO"
		},
		{
			4242,
			{MARDI, 13, MAI, 1997},
			"BIERE"
		},
		{
			4894613,
			{MERCREDI, 14, MAI, 1997},
			"VIN BLANC"
		},
	};

	for (int i = 0; i < 3; ++i){
		printf("%d\n", etudiants[i].id);
		printf("%02d/%02d/%04d\n", etudiants[i].dateDeNaissance.jour, etudiants[i].dateDeNaissance.mois, etudiants[i].dateDeNaissance.annee);
		printf("%s\n\n", etudiants[i].boissonPref);
	}

	return 0;
}

