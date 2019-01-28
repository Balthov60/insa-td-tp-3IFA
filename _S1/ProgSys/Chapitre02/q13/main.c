#include <stdio.h>


int main(int argc, char const *argv[]){
	
	int tab[2][2] = {{1, 2}, {3, 4}};

	printf("Si 2 : * prioritaire sur []\n" );
	printf("Si 3 : [] prioritaire sur *\n" );
	printf("--> %d <--\n", *tab[1]);
	
	return 0;
}

