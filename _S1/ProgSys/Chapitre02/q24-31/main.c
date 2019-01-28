#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NB_CARTES_MAX 32
#define NB_CARTES 8

typedef enum {COEUR, CARREAU, PIQUE, TREFLE} couleur_t;
typedef enum {SEPT, HUIT, NEUF, DIX, VALET, DAME, ROI, AS} valeur_t;

typedef struct {
	valeur_t valeur;
	couleur_t couleur;
	int played;
} carte_t;

carte_t JeuComplet[NB_CARTES_MAX];
carte_t CartesOrdi[NB_CARTES];
carte_t CartesJoueur[NB_CARTES];

void init_jeu(){
	for (int i = 0; i < NB_CARTES_MAX; ++i){
		carte_t carte = {(valeur_t) i % 8, (couleur_t) i / 8, 0};
		JeuComplet[i] = carte;
	}
}

void afficher_carte(carte_t carte){
	char* chaines_couleur[4] = {"Coeur", "Carreau", "Pique", "Trefle"};
	char* chaines_valeur[8]={"7", "8", "9", "10", "Valet", "Dame", "Roi", "As"};

	printf("%s de %s\n", chaines_valeur[carte.valeur], chaines_couleur[carte.couleur]);
}

void melange_jeu(carte_t *jeu){
	for (int i = 0; i < NB_CARTES_MAX * NB_CARTES_MAX; ++i){
		for (int j = 0; j < NB_CARTES_MAX; ++j){
			carte_t tmp = JeuComplet[j];
			int rnd = rand() % 32;

			JeuComplet[j] = JeuComplet[rnd];
			JeuComplet[rnd] = tmp;
		}
	}
}

void distribue(){
	for (int i = 0; i < NB_CARTES; ++i){
		CartesJoueur[i] = JeuComplet[i];
	}

	for (int i = 0; i < NB_CARTES; ++i){
		CartesOrdi[i] = JeuComplet[i + 8];
	}
}


void jeu(){
	int round = 0;
	//int iPlayedJoueur[NB_CARTES];
	//int iPlayedOrdi[NB_CARTES];
	int indexC = 0;
	int indexO = 0;
	int pointC = 0;
	int pointO = 0;

	do{

		printf("\nCartes a jouer:\n");
		for (int i = 0; i < NB_CARTES; ++i){
			if(CartesJoueur[i].played == 0){
				printf("  -> %d: ", i);
				afficher_carte(CartesJoueur[i]);
			}
		}

		printf("\nNumero de la carte a jouer ?\n");
		scanf("%d", &indexC);
		CartesJoueur[indexC].played = 1;

		system("clear");

		do{
			indexO = rand() % NB_CARTES;
		}while(CartesOrdi[indexO].played == 1);

		if(CartesOrdi[indexO].valeur > CartesJoueur[indexC].valeur ){
			pointO++;
			printf("Perdu. Score: %d-%d\n",pointC, pointO );
		}else if(CartesOrdi[indexO].valeur < CartesJoueur[indexC].valeur ){
			pointC++;
			printf("Gagne. Score: %d-%d\n",pointC, pointO );
		}else{
			pointC++;
			pointO++;
			printf("Equalite. Score: %d-%d\n",pointC, pointO );
		}

		round++;
	}while(round < NB_CARTES);
	
	system("clear");

	printf("FIN DU JEU.\n ORDI:\t%d\n TOI: \t%d", pointO, pointC);
}

int main(int argc, char const *argv[]){
	srand(time(NULL));

	init_jeu();

	melange_jeu(JeuComplet);
	distribue();

	jeu();

	return 0;
}

