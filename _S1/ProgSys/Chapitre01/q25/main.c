#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#define MASQUE(v) (1 << ((v) - 1)) 

bool estVide (uint32_t allRooms, unsigned int roomNum){
	return (allRooms & MASQUE(roomNum)) != MASQUE(roomNum);
}

int main(){

	// Numéros chambre:     987654321
	// Etat des chambres: 0b000010010 -> 18 (base 10)
	
	uint32_t allRooms = 18;

	printf("Chambre 1: %s\n", estVide(allRooms, 1) ? "vide" : "pleine");
	printf("Chambre 2: %s\n", estVide(allRooms, 2) ? "vide" : "pleine");
	printf("Chambre 3: %s\n", estVide(allRooms, 3) ? "vide" : "pleine");
	printf("Chambre 4: %s\n", estVide(allRooms, 4) ? "vide" : "pleine");
	printf("Chambre 5: %s\n", estVide(allRooms, 5) ? "vide" : "pleine");

	return 0;
}