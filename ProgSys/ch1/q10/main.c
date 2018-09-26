#include <stdio.h>
#include <stdint.h>

int main(){

    //           2147483647  <- max uint32
	uint32_t a,
	         b = 2000000000,
	         c = 1000000000,
	         d = 1500000000;


	// (b + c) > 2147483647
	a = (b + c) - d;

    // Mais le resultat est correct
	printf("%d\n", a);

	return 0;
}