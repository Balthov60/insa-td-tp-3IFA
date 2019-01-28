#include <stdio.h>
#include <stdint.h>

int main(){

	if (sizeof(int) < -1){
		printf("Bizarre, bizarre, ...\n");
	}else{
		printf("Tout est normal.\n");
	}

	// Le probleme c'est que sizeof(int) revoit un unsigned
	// or pour que la conversion soit correct il faut que les
	// deux types soient identiques. -1 est implicitement caster 
	// en unsigned int, il vaut maintenant 4294967295.
	//
	// 4 < 4294967295  <- false
	
	printf("-1 en unsigned: %u\n", -1);

	return 0;
}