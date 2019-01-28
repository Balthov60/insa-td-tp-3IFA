#include <stdio.h>
#include <stdint.h>

int main(){

	long int a = 8000000002;
	float b = 2;

	long int c =  a / b;
	long int d = ((double) a) / b;

	printf("res: %li // Not good\n", c);
	printf("res: %li // Good\n", d);

	return 0;
}