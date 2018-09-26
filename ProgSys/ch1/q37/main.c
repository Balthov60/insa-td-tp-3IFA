#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

void shadokifier(int number){
	do{
		switch(number % 4){
			case 0: 
				printf("Ga ");
				break;
			case 1: 
				printf("Bu ");
				break;
			case 2: 
				printf("Zo ");
				break;
			case 3: 
				printf("Meu ");
				break;
		}

		number -= number % 4;
		number /= 4;

	}while(number != 0);

	printf("\n");
}

int main(){
	for (int i = 0; i < 20; ++i){
		shadokifier(i);
	}
}
