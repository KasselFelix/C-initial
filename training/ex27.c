#include <stdio.h>
#include <stdlib.h>


typedef struct _cellule_t cellule_t;
struct _cellule_t{
	int donnee;
	cellule_t *suivant;
};

cellule_t *Creer_cellule(int d){
	cellule_t *ncell=malloc(sizeof(cellule_t));
	ncell->donnee=d;
	ncell->suivant=NULL;
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

int main(){
	cellule_t *tete=NULL;
	tete=Creer_cellule(1);
	tete->suivant=Creer_cellule(2);
	tete->suivant->suivant=Creer_cellule(3);
	Afficher_liste_int(tete);
	return 0;
}
