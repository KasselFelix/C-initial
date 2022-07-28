#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define NB_JOURS 7
#define NB_AMIS 4

void init0(int depense[NB_JOURS][NB_AMIS]){
	int i,j;
	for(i=0;i<NB_JOURS;i++){
		for(j=0;j<NB_AMIS;j++){
			depense[i][j]=0;
		}
	}
}

void compteJ(int depense[NB_JOURS][NB_AMIS]){
	int i,j;
	int som;
	int amis;
	printf("--------------------------------------------------------------------\n");
	for(i=0;i<NB_JOURS;i++){
			printf("%d       |       ",i);
			amis=rand()%(NB_AMIS);
			som=30+rand()%21;
			for(j=0;j<NB_AMIS;j++){
				if(i==amis){
				depense[i][j]=som-(som/NB_AMIS);
				//printf("jour %d : %d paye %d\n",i+1,j,depense[i][j]);
				}else{
			
				depense[i][j]=-(som/NB_AMIS);
			}
			printf("%d\t",depense[i][j]);
		}
		printf("\n");
	}
}

int calcul(int m, int depense[NB_JOURS][NB_AMIS]){
	int solde=0;
	int i,j;
	for(i=0;i<NB_JOURS;i++){
		for(j=0;j<NB_AMIS;j++){
			if(i==m){
				solde=solde+depense[i][j];
			}
		}
	}
	return solde;
}


int main(){
	int i;
	srand(time(NULL));
	int depense[NB_JOURS][NB_AMIS];
	init0(depense);
	printf("        |       ");
	for(i=0;i<NB_JOURS;i++){
		printf("%d\t",i+1);
	}
	printf("\n");
	compteJ(depense);
	
	
	for(i=0;i<NB_AMIS;i++){
		printf("solde %d: %d\n",i+1,calcul(i,depense));
	}
	return 0;
}
