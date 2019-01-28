#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SAPIN_COUNT 8

typedef struct {
	int height;
	int width;
} sapin_t;

void print_pine(sapin_t *sapin){

	for (int i = 0; i < (*sapin).height; ++i){
		int starsLimit = i*2+1;
		int spaceLimit = i+(*sapin).height-starsLimit;

		for (int j = 0; j < spaceLimit; ++j){
			printf(" ");
		}

		for (int j = 0; j < starsLimit; ++j){
			printf("*");
		}

		printf("\n");
	}

	for (int k = 0; k < 2; ++k){
		for (int i = 0; i < (*sapin).height-(*sapin).width/2-1; ++i){
			printf(" ");
		}

		for (int i = 0; i < (*sapin).width+1; ++i){
			printf("|");
		}

		printf("\n");
	}
	
}

void populate_forest(sapin_t *sapin){
	(*sapin).height = rand() % 20 + 2;
	(*sapin).width = rand() % 7 + 2;
}

int main(int argc, char const *argv[]){
	srand(time(NULL));

	sapin_t sapins[SAPIN_COUNT];

	for (int i = 0; i < SAPIN_COUNT; ++i){
		populate_forest(&sapins[i]);
		print_pine(&sapins[i]);
		printf("\n\n");
	}


	return 0;
}

