#include <stdio.h>
#include <stdint.h>

int main(){

	char c1 = 42;
	int i1 = c1;

	int i2 = 42;
	char c2 = i2;

	printf("Char dans int: %d\n", i1);
	printf("Int dans char: %c\n", c2);

	return 0;
}