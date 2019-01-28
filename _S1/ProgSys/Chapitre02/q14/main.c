#include <stdio.h>


int main(int argc, char const *argv[]){
	
	int tab[5][7];

	tab[1][5] = 0;
	tab[2][2] = 0;

	*(tab + 12) = 1;
	printf("*(tab + 12) permet d'acceder à %s\n",  
		tab[1][5] == 1 ? "tab[1][5]" : "tab[2][2]");
	
	return 0;
}

