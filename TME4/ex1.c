#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define N 31

float *init_temp(){
	int i;
	float *tab;
	tab=malloc(N* sizeof(float));
	for (i=0;i<N;i++){
		tab[i]=(-200+rand()%501)/10.0;
	}
	return tab;
}

/*void init_tab(float tab[]){
	int i;
	for (i=0; i<N; i++){
	tab[i]=(-200+rand()%501)/10.0;
	}
}*/

void affiche(float tab[]){
	int i;
	for(i=0;i<N;i++){
		printf("%.2f\t",tab[i]);
	}
	printf("\n");
}

float moy_temp(float tab[]){
	int i;
	float s=0.0;
	for(i=0;i<N;i++){
		s=s+*(tab+i);
	}
	return s/N;
}

float f(float tab[]){
	int i;
	float s=0.0,cpt=0.0;

	for(i=0;i<N;i++){
		if(tab[i]>0){
            s=s+*(tab+i);
            cpt++;
		}
	}

	if(cpt==0)printf("Aucune temperature au-dessous de zero.");
	return s/cpt;
}

int main(){
	srand(time(NULL));
	float *tab=init_temp();
	affiche(tab);
	printf("moy : %.2f\n",moy_temp(tab));//si moy proche de 5=-20+(30/2) , quand N est tres grand
	printf("f(tab)=%.2f\n",f(tab));
	free(tab);
	return 0;
}
