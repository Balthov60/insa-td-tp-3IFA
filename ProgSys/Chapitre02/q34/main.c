#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int proba(int i){
	return rand() % 100 > (100-i);
}

void generate_pine(){

	int height = rand() % 20 + 2;
	int width = rand() % 7 + 2;

	for (int i = 0; i < height; ++i){
		int starsLimit = i*2+1;
		int spaceLimit = i+height-starsLimit;

		for (int j = 0; j < spaceLimit; ++j){
			printf(" ");
		}

		for (int j = 0; j < starsLimit; ++j){
			if(proba(20)){
				printf("O");
			}else{

				printf("*");
			}
		}

		printf("\n");
	}

	for (int k = 0; k < 2; ++k){
		for (int i = 0; i < height-width/2-1; ++i){
			printf(" ");
		}

		for (int i = 0; i < width+1; ++i){
			printf("|");
		}

		printf("\n");
	}
	
}

int main(int argc, char const *argv[]){
	srand(time(NULL));

	generate_pine();

	return 0;
}

