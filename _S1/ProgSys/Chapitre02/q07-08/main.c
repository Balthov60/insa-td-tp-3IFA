#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

int main(int argc, char const *argv[]){
	
	char str[] = "<-_->";

	int len = sizeof(str) / sizeof(char) - 1;

	for (int i = 0; i < len; ++i){
		printf("%c%c", str[i], (i != len - 1) ? '.' : ' ');
	}

	return 0;
}

