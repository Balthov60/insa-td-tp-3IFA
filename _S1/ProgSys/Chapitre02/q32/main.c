#include <stdio.h>


void drawPine(int height, int width ){

	for (int i = 0; i < height; ++i){
		int starsLimit = i*2+1;
		int spaceLimit = i+height-starsLimit;

		for (int j = 0; j < spaceLimit; ++j){
			printf(" ");
		}

		for (int j = 0; j < starsLimit; ++j){
			printf("*");
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

	drawPine(6,2);

	return 0;
}

