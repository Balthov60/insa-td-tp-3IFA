#include <stdio.h>
#include <stdint.h>

int main(){

	printf("Long:\n");
	printf("  - Octets: %d\n", (int) sizeof(long));
	printf("  - Bits: %d\n", (int) sizeof(long) * 8);

	printf("\n");

	printf("Long long:\n");
	printf("  - Octets: %d\n", (int) sizeof(long long));
	printf("  - Bits: %d\n", (int) sizeof(long long) * 8);

	return 0;
}