#include <stdio.h>
#include <stdint.h>

int main(){

	// Le compilateur va implicitement convertir le double
	// 1.618 en entier. On aura donc juste 1.
	
	int i = 1.618;

	printf("%d\n", i);

	return 0;
}