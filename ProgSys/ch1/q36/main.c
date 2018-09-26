#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

/*
	Le probleme de ce programme est que la fonction "void appreciate()"
	n'a pas de parametre d'entré. La variable "note" n'est pas définie.
*/

void appreciate(){
	switch (note) {
		case 12:
			printf("12 ! Passable ");
		break;
		case 18:
			printf("18 ! Super ! ");
		case 6:
			printf("6 ! Naze ");
		break;
		case 8:
			printf("8 ! Mieux que naze ");
		break;
		case 10:
			printf("10 ! Presque passable ");
		break;
		default:
			printf("%d ! Pas prevu par le de-qui-corrige", note);
		break;
	}
	printf("\n");
}

void main(){
	appreciate(6);
	appreciate(12);
	appreciate(18);
	appreciate(14);
}