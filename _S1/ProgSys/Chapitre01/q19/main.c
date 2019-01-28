#include <stdio.h>
#include <stdint.h>

int main(){

	// Si un seul des opérande est est de type flottant, 
	// le type entier est converti dans ce type flottant.


	float f = 1.2;
	long l = 10;

	printf("%f\n", (f + l));

	return 0;
}