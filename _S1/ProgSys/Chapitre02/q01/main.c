#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

/*
	Enlever le flag "-pedantic"
	pour que ça marche.
*/

// Le pointeur de la fonction main est stocké dans le Text segment

int main(int argc, char const *argv[]){
	
	printf("%p\n", (void*) &main);

	return 0;
}

