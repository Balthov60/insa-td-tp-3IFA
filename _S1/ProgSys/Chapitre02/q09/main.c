#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

int main(int argc, char const *argv[]){
	
	char str[] = "<-_->";

	int len =  strlen(str);

	for (int i = 0; i < len; ++i){
		printf("%c%c", str[i], (i != len - 1) ? '.' : ' ');
	}

	return 0;
}

