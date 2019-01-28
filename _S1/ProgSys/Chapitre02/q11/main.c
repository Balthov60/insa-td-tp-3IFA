#include <stdio.h>

int TP_strcmp(const char *s1, const char *s2){
	int i = 0;
		
	while(s1[i] != 0 && s2[i] != 0){

		if(s1[i] != s2[i])
			return s1[i] - s2[i];
		
		i++;
	}

	return 0;
}

int main(int argc, char const *argv[]){
	
	printf("AZERTY & AZERTY : %d\n", TP_strcmp("AZERTY", "AZERTY"));
	printf("AZERTY & QSDFGH : %d\n", TP_strcmp("AZERTY", "QSDFGH"));
	printf("AZERTY & AzERTY : %d\n", TP_strcmp("AZERTY", "AzERTY"));
	printf("AzERTY & AZERTY : %d\n", TP_strcmp("AzERTY", "AZERTY"));

	return 0;
}

