#include <stdio.h>

int jours(int nb_c, int pop,float pourcen){
	int jour=0,c=1;
	while(c < (pourcen/100.0)*pop){
		c=c+c*nb_c;
		jour++;
	}
	return jour;
}

float pourcentage(int nb_c, int pop, int jour){
	int i; 
	float c=1.0;
	for(i=0;i<jour && c<pop;i++){
		c=c+c*nb_c;
	}
	return (c/pop)*100.0;
}

int main(){
	int jour = 6,nb_c=1,pop=100;
	float pourcen=50.0;
	printf("le nombre de jours au bout duquel %.2f pourcents de la ville est contaminé est : %d jour\n",pourcen,jours(nb_c,pop,pourcen));
	printf("le pourcentage de la population contaminé au bout de %d jour est : %.2f pourcents\n",jour,pourcentage(nb_c,pop,jour));
	return 0;
}
