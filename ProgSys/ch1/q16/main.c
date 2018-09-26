#include <stdio.h>
#include <stdint.h>

int main(){

	int16_t a = 413;
	uint16_t b = 64948;
	printf("%u - %u => %u\n", a, b, (a - b));
             
	return 0;
}