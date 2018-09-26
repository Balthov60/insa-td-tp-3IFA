#include <stdio.h>
#include <stdint.h>

int main(){

    int i1 = -42;
    unsigned int u1 = i1;

    int i2 = 4096;
    char c2 = i2;

    printf("-42 dans un unsigned: %u\n", u1);
    printf("4096 dans un char: %d\n", c2);

    // Char: seulement 8bits (un octet)
    // 4096 en binaire: 100000000000
    //              c2 =    00000000
    //
    // Seul les 8 premiers bits (LSB)
    // sont conservés -> grosse perte 
    // d'information.

	return 0;
}