#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NB_VALEURS 1000

void minimum_maximum(int *min, int *max, int val) {
	/* modifie la plus petite valeur entre val et valMin */
	if (val < *min) {
		*min=val;
	}	
	
	/* modifie la plus grande valeur entre val et valMax */
	if (val > *max) {
		*max=val;
	}

}


int main(){
	int i,val;
	int min=RAND_MAX, max=0;
	
	/* initialisation du générateur de nombres aléatoires */
	srand(time(NULL));
	
	for (i=0; i < NB_VALEURS; i++) {
		val=10+rand()%21;
		printf("%d\n",val);
		minimum_maximum(&min,&max,val);
	}
	printf("MIN = %d, MAX = %d\n", min,max);
	return 0;
}
