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
	
	etudiant_t etudiant = {
		666,
		{LUNDI, 12, MAI, 1997},
		"MOJITO"
	};

	printf("%d\n", etudiant.id);
	printf("%02d/%02d/%04d\n", etudiant.dateDeNaissance.jour, etudiant.dateDeNaissance.mois, etudiant.dateDeNaissance.annee);
	printf("%s\n", etudiant.boissonPref);

	return 0;
}

