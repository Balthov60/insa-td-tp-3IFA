#include <stdio.h>


int main(){

	int depassement = 1 << 31;

	printf("2^32 = %d\n", depassement);
	printf("(Valeur max d'un int8_t: 2147483647)\n");

	printf("%d\n",(char) 0xFFFFFFFF + 1);

	return 0;
}