#include <stdio.h>


int main(){

	int pi1 = 3.14;
	float pi2 = 3.14;
	float pi3 = 3.14159265358979323846264338327;
	double pi4 = 3.14159265358979323846264338327;

	int diameter = 5;

	printf("%i\n", pi1 * diameter);
	printf("%f\n", pi2 * diameter);
	printf("%f\n", pi3 * diameter);
	printf("%f\n", pi4 * diameter);

	return 0;
}