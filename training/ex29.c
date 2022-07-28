#include <stdio.h>
#include <stdlib.h>

typedef struct _cellule_t cellule_t;
struct _cellule_t{
int donnee;
cellule_t *suivant;
};

cellule_t* Creer_cellule(int d){
	cellule_t *ncell=malloc(sizeof(cellule_t));
	ncell->donnee=d;
	ncell->suivant=NULL;
	return ncell;
}

cellule_t* Inserer_tete(int d, cellule_t* liste){
	cellule_t *n;
	n= Creer_cellule(d);
	n->suivant=liste;
	return n;
}

cellule_t* Inserer_fin_it(int d, cellule_t* liste){
	cellule_t *deb=liste;
	cellule_t *ncell=malloc(sizeof(cellule_t));
	ncell->donnee=d;
	ncell->suivant=NULL;
	if(liste){
		while(liste->suivant){
			liste=liste->suivant;
		}
		liste->suivant=ncell;
		return deb;
	}
	return ncell;
}


void Afficher_liste_int(cellule_t *liste){
	cellule_t *cell = liste;
	while (cell != NULL) {
		printf("%d ", cell->donnee);
		cell = cell->suivant;
	}
	printf("\n");
}

cellule_t *Creer_liste_alea(int val_max, int nb_val ){
	srand(time(NULL));
	cellule_t *liste;
	
	while(nb_val>=1){
		liste=Inserer_fin_it(rand()%val_max,liste);
		nb_val--;
	}
	return liste;
}

int main(){
    cellule_t *tete=NULL;
    int i;
    for(i=1;i<6;i++){
    	tete=Inserer_fin_it(i,tete);
    }
    for(i=1;i<6;i++){
    	tete=Inserer_tete(i,tete);
    }
    Afficher_liste_int(tete);
    return 0;
}
