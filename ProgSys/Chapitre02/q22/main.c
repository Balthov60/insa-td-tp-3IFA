#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]){

	if(argc != 2) {
		printf("Passez un nom en parametre.\n");
		return -1;
	}

	for (int i = 0; i < atoi(argv[1]); ++i){
		printf("*");
	}

	return 0;
}

