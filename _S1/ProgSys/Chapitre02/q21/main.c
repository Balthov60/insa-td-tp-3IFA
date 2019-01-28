#include <stdio.h>

int main(int argc, char const *argv[]){

	printf("Nombre de parametres: %d\n", argc);
	printf("Premier param (sans les quotes): \"%s\"\n", argv[0]);

	return 0;
}

