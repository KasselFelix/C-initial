#include <stdio.h>
#include <stdlib.h>

typedef struct _cellule_t cellule_t;
	struct _cellule_t{
	int donnee;
	cellule_t *suivant;
};

cellule_t *cons(int n,cellule_t *li){
	cellule_t *liste=malloc(sizeof(cellule_t));
	liste->donnee=n;
	liste->suivant=li;
	return liste;
}

cellule_t *add(int max,cellule_t *liste){
    cellule_t *l=liste;
    int i=5;
    while (i>=0){
        l=cons(i,l);
        i++;

    }

    
    return l;
}


void Afficher_liste_int(cellule_t *liste){
	cellule_t *cell = liste;
	while (cell!=NULL) {
		printf("%d ", cell->donnee);
		cell = cell->suivant;
	}
	printf("\n");
}


int main(){

	cellule_t *ns=NULL;
	ns=add(5,ns);
   Afficher_liste_int(ns);
	return 0;
}
