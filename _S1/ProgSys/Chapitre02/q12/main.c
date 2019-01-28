#include <stdio.h>

// Utilisation de gdb pour afficher la valeure des adresses des pointeurs.

int main(int argc, char const *argv[]){
	
	int tab[5][7];
	int* tab_addr = &tab;
	int* tab_point = tab;
	int* tab_point_elt = &tab[0];

	return 0;
}

