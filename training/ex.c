#include <stdio.h>
#include <stdlib.h>

typedef struct _cellule_t cellule_t;
	struct _cellule_t{
	int donnee;
	cellule_t *suivant;
};

cellule_t *con(int n,cellule_t *l){
	cellule_t *liste=malloc(sizeof( cellule_t));
	liste->donnee=n;
	liste->suivant=l;
	return liste;
}

void Afficher_liste_int(cellule_t *liste){
	while (liste->suivant!=NULL) {
		printf("%d ", liste->donnee);	
		liste = liste->suivant;
	}
	printf("\n");
}

int main(){

	cellule_t *ns;
	ns=con(1,con(2,con(3,con(4,con(5,NULL)))));
}

