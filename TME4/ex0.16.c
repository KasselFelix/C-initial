#include <stdio.h>
#include <stdlib.h>
#define TAILLE 10

void affiche(float tab[], int p){
	int i;
	for (i=0;i<TAILLE;i++){
		if(i%p ==0 && i!=0){
			printf("\na");
		}
		printf("%f\t",tab[i]);	
	}
}

int main(){
	int p=5;
	float tab[TAILLE]={1.0,2.0,3.0,4.0,5.0,6.0,7.0,8.0,9.0,10.0};
	affiche(tab,p);
	return 0;
}
