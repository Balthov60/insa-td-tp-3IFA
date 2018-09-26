#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#define MASQUE(v) (1 << ((v) - 1)) 

bool isOccupied (uint32_t allRooms, unsigned int roomNum){
	return (allRooms & MASQUE(roomNum)) == MASQUE(roomNum);
}

uint32_t roomGoesOccupied (uint32_t allRooms, unsigned int roomNum){
	return allRooms |= MASQUE(roomNum);
}

uint32_t roomGoesEmpty (uint32_t allRooms, unsigned int roomNum){
	return allRooms &= ~MASQUE(roomNum);
}

void printRoomsState(uint32_t allRooms){
	for (int i = 1; i <= 32; ++i){
		printf("Room %d: \t%s\n", i, isOccupied(allRooms, i) ? "occupied" : "empty");
	}
}

int main(){
	uint32_t allRooms = 0;

	allRooms = roomGoesOccupied(allRooms, 1);
	allRooms = roomGoesOccupied(allRooms, 2);
	allRooms = roomGoesOccupied(allRooms, 20);
	allRooms = roomGoesOccupied(allRooms, 7);
	allRooms = roomGoesOccupied(allRooms, 15);

	allRooms = roomGoesEmpty(allRooms, 15);

	printRoomsState(allRooms);
	return 0;
}
