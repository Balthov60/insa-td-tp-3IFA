#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#define MASQUE(v) (1 << ((v) - 1)) 

typedef uint32_t ensemble;

bool isOccupied (ensemble allRooms, unsigned int roomNum){
	return (allRooms & MASQUE(roomNum)) == MASQUE(roomNum);
}

ensemble roomGoesOccupied (ensemble allRooms, unsigned int roomNum){
	return allRooms |= MASQUE(roomNum);
}

ensemble roomGoesEmpty (ensemble allRooms, unsigned int roomNum){
	return allRooms &= ~MASQUE(roomNum);
}

void printRoomsState(ensemble allRooms){
	for (int i = 1; i <= 32; ++i){
		printf("Room %d: \t%s\n", i, isOccupied(allRooms, i) ? "occupied" : "empty");
	}
}

int main(){
	ensemble allRooms = 0;

	allRooms = roomGoesOccupied(allRooms, 1);
	allRooms = roomGoesOccupied(allRooms, 2);
	allRooms = roomGoesOccupied(allRooms, 20);
	allRooms = roomGoesOccupied(allRooms, 7);
	allRooms = roomGoesOccupied(allRooms, 15);

	allRooms = roomGoesEmpty(allRooms, 15);

	printRoomsState(allRooms);
	return 0;
}