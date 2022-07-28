#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int choix_ordinateur(){

	return 1+rand()%3;
}

int choix_joueur(){
	int j,i=0;
	do{
		printf(" _________   _________   _________ \n| Pierre  | | Feuille | | ciseaux |\n|    1    | |    2    | |    3    |\n|_________| |_________| |_________|\n");
		scanf("%d",&j);
		i++;
		if(j<=3 && j>=1){
			return j;
		}
	}while(i<3 && (j>=3 || j<=1));
	j=1+rand()%3;
	return j;
}

void score(int j,int o,int *scorej,int*scoreo){

	if((j==1 && o==2) || (j==2 && o==3) || (j==3 && o==1)){
        (*scoreo)++;
	}
	if((j==1 && o==3) || (j==2 && o==1) || (j==3 && o==2)){
        (*scorej)++;
	}
}

void jeu(){
	int scorej=0,scoreo=0;
	int cj,co;
	printf("============================================\n");
	printf("                  JANKEN!!!                 \n");
	printf("============================================\n\n");
	while(scorej<3 && scoreo<3){
		cj=choix_joueur();
		co=choix_ordinateur();
		if (co==1){
            	printf("ordinateur utilise : Pierre\n");
		}
		if (co==2){
            	printf("ordinateur utilise : Feuille\n");
		}
        	if (co==3){
            	printf("ordinateur utilise : Ciseaux\n");
		}
		score(cj,co,&scorej,&scoreo);
		printf("[joueur] : %d\n",scorej);
		printf("[ordinateur] : %d\n",scoreo);
	}
	if(scoreo==3){
        printf("============================================\n\n         DEFAITE\n\n============================================\n");
	}
	else{
        printf("============================================\n\n        VICTOIRE\n\n============================================\n");
	}

}


int main(){
	srand(time(NULL));
	jeu();
	return 0;
}
