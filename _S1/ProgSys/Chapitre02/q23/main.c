#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]){

	printf("\nfoo() = 2\n  -> incorrect\n");
	printf("\nint var = 0; 4 = var;\n  ->  incorrect\n");
	printf("\nint var = 0; (var + 1) = 4;\n  ->  incorrect\n");
	printf("\nint arr[] = {1, 2};\nint* p = &arr[0];\n*(p + 1) = 10;\n  ->  incorrect\n");
	printf("\nint var = 10;\nint* addr = &(var +1);\n  ->  incorrect\n");
	printf("\nenum color { red, green, blue };\ncolor c;\nc = green;\nblue = green;\n ->  incorrect\n");
	printf("\nvar = 40;\n  ->  incorrect\n");
}

