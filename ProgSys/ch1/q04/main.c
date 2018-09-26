#include <stdio.h>

int main(){
	char test = 0;

	if(--test == -1){
		printf("Le type char est signe.\n\n");
	}else{
		printf("Le type char n'est PAS signe.\n\n");
	}

	printf("char test = 0;\n");
	printf("test--; -> %d\n", test);

	return 0;
}