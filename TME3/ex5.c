# include <stdio.h>

void afficheLignes(int longueur, int max){
	int i;
	for(i=1;i<=max;i++){
		if((i-1)%longueur ==0 && i!=0){
			printf("\n");
		}
		printf("%d\t",i);
	}
	printf("\n");
}

void saisie_affichage(){
	int longueur,max;
	printf("veuiller selectionner la longueur\n");
	scanf("%d",&longueur);
	printf("veuiller selectionner la valeur max\n");
	scanf("%d",&max);
	afficheLignes(longueur,max);
}

int main(){
	saisie_affichage();
	return 0;
}
