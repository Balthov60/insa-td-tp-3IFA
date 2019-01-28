#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include <string.h>

int main(int argc, char const *argv[]){
	
	char str[10], *endptr;
	intmax_t i;

	scanf("%s", str);	
	i = strtoimax(str, &endptr, 10);

	printf("%jd\n", i);
	return 0;
}

