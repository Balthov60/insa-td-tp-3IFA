#include <stdio.h>
#include <limits.h>

int main(){

	int sTaille = sizeof(int) * 8;
	int sMax = ((1 << (sTaille - 1)) + 1) * -1;
	int sMin = (1 << (sTaille - 1));

	int uTaille = sizeof(unsigned int) * 8;
	int uMax = (1 << sTaille) * -1;

	printf("Signed int:\n");
	printf("  - Taille: %d octets (%d bits)\n", (int) sizeof(int), sTaille);
	printf("  - Max: %d\n", sMax);
	printf("  - Min: %d\n", sMin);

	printf("\n\n");

	printf("Unsigned int:\n");
	printf("  - Taille: %d octets (%d bits)\n", (int) sizeof(int), uTaille);
	printf("  - Max: %u\n", uMax);
	
	return 0;
}