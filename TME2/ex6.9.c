#include <math.h>
#include <stdio.h>

void decomposition_somme(int som){
	int cinq=0,deux=0,un=0,n =som;
	cinq=som/5;
	n=som%5;
	deux= n/2;
	un =n%2;
	printf("%d*5 + %d*2 + %d*1\n",cinq,deux,un);
}

void decomposition_multiple_somme(int som){
	int cinq=0,deux=0,un=0, cpt=1,i=1;
	while (cpt <= som-5){
		cpt=cpt+5;
		cinq++;
		while(i <= som-cinq){
			i=i+2;
			deux++;
		
		}
		printf("%d*5 + %d*2 + %d*1\n",cinq,deux,un);
	}
}

int main(){
/*	decomposition_somme(53);*/
	decomposition_multiple_somme(12);
	return 0; 
}
