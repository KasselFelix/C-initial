#include<stdio.h>
#include<stdlib.h>
typedef struct cellule_t cellule_t;
struct cellule_t{
	int donnee;
	cellule_t*suivant;
};

cellule_t *Inserer_fin_it( int d, cellule_t *liste){
	cellule_t *cell=liste;
	cellule_t *ncell=malloc(sizeof(cellule_t));
	ncell->donnee=d;
	ncell->suivant=NULL;
	if(liste){
		while(liste->suivant){
			liste=liste->suivant;
		}
		liste->suivant=ncell;
		return cell;
	}
	return ncell;
}
int nb_occurences(int val, cellule_t *liste){
	int cpt=0;
	while(liste){
		if(liste->donnee == val){
			cpt=cpt+1;
		}
		liste=liste->suivant;
	}
	return cpt;
}
int tous_plus_grand(int val, cellule_t *liste){
	while(liste){
		if(liste->donnee <val){
			return 0;
		}
		liste=liste->suivant;
	}
	return 1;
}
cellule_t *maximum(cellule_t *liste){
	int tmp=liste->donnee;
	while(liste){
		if(tmp<liste->suivant->donnee){
			tmp=liste->suivant->donnee;
		}
		liste=liste->suivant;
	}
	return liste;
		
}
int nb_maximum(cellule_t *liste){
	int o_max=0;
	int max=liste->donnee;
	while(liste->suivant){
		if( liste->suivant->donnee >max){
		max=liste->suivant->donnee;
		o_max=0;
		}
		if(liste->suivant->donnee == max){
			o_max++;
		}
		liste=liste->suivant;
		
	}
	return o_max;
}
int main(){
	cellule_t *liste=NULL;
	/*cellule_t *grand;*/
	int i;
	for(i=0;i<5;i++){
		liste=Inserer_fin_it(i,liste);
	}
	liste=Inserer_fin_it(5,liste);
	liste=Inserer_fin_it(5,liste);
	/* nombre d'occurence */
	printf("il y a %d occurences\n",nb_occurences(5,liste));
	/*affichage de la liste*/
	printf("Est-ce que tous les element sont supérieur à notre valeur(1=vrai)(0=faux): %d \n",tous_plus_grand(3,liste));
	while(liste){
		printf("%d \t",liste->donnee);
		liste=liste->suivant;
	}
	printf("\n");
	/*grand=maximum(liste);
	printf("%d\n",grand->donnee);*/
	printf("il y a %d occurence max",nb_maximum(liste));
	return 0;
}
