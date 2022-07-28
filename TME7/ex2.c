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

cellule_t *supprimer_element_it(cellule_t *liste, int val){
	cellule_t *tmp;
	cellule_t *p;
	if(liste==NULL){
		return NULL;	
	}
	if(liste->donnee==val){
		tmp=liste->suivant;
		free(liste);
		return tmp;
	}
	p=liste;
	while(p->suivant->donnee != val && p->suivant != NULL){
		p=p->suivant;
	}
	if(p->suivant != NULL){
		tmp=p->suivant;
		p->suivant=tmp->suivant;
		free(tmp);
	}
	return liste;
}

void afficher(cellule_t *liste){
	while(liste){
		printf("%d",liste->donnee);
		liste=liste->suivant;
	}
	printf("\n");
}

cellule_t *Dupliquer_liste(cellule_t *liste){
	cellule_t *new=NULL;
	while(liste){
		new=Inserer_fin_it(liste->donnee,new);
		liste=liste->suivant;
	}
	return new;
}

int main(){
	cellule_t *liste=NULL;
	int i;
	for(i=0;i<5;i++){
		liste=Inserer_fin_it(i,liste);
	}
	liste=Inserer_fin_it(5,liste);
	supprimer_element_it(liste,4);
	afficher(liste);
	cellule_t *new=Dupliquer_liste(liste);
	afficher(new);
	return 0;
}

