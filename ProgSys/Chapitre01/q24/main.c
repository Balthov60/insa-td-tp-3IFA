#include <stdio.h>
#include <stdint.h>

int main(){

    char A = 3;
    int B = 4;

    // On force explicitement le conpilateur 
    // a interpreter le char comme un flottant. 
    // Puis B est implicitement convertit en float.

    float C = ((float) A) / B;

    printf("%f\n", C);

	return 0;
}