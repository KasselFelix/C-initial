#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define NB_JOURS 7
#define NB_AMIS 4

void init0(float depense[NB_AMIS][NB_JOURS]){
	int i,j;
	for(i=0;i<NB_AMIS;i++){
		for(j=0;j<NB_JOURS;j++){
			depense[i][j]=0;
		}
	}
}

void compteJ(float depense[NB_AMIS][NB_JOURS]){
	int i,j;
	float som;
	int amis;
	for(j=0;j<NB_JOURS;j++){
			amis=rand()%(NB_AMIS);
			som=30+rand()%21;
			for(i=0;i<NB_AMIS;i++){
				if(i==amis){
					depense[i][j]=som*(1-1.0/NB_AMIS);
					printf("jour %d : %d paye %.2f\n",i+1,j,depense[i][j]);
				}else{
			
				depense[i][j]=-som *(1.0/NB_AMIS);
				}
			}
	}
	
}


float calcul(int m, float depense[NB_AMIS][NB_JOURS]){
	float solde=0.0;
	int i,j;
	for(i=0;i<NB_AMIS;i++){
		for(j=0;j<NB_JOURS;j++){
			if(i==m){
				solde=solde+depense[i][j];
			}
		}
	}
	return solde;
}


int main(){
	int i,j;
	srand(time(NULL));
	float depense[NB_AMIS][NB_JOURS];
	init0(depense);
	compteJ(depense);
	printf("        |       ");
	for(i=0;i<NB_JOURS;i++){
		printf("%d\t",i+1);
	}
	printf("\n");
	printf("--------------------------------------------------------------------\n");

	for(j=0;j<NB_AMIS;j++){
		printf("        |       ");
		for(i=0;i<NB_AMIS;i++){
			printf("%.2f\t",depense[i][j]);
		}
		printf("\n");
	}
	
	for(i=0;i<NB_AMIS;i++){
		printf("solde %d: %.2f\n",i+1,calcul(i,depense));
	}
	return 0;
}
