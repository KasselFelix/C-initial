#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include "liste_entiers.h"
#include "liste_Ensemble.h"


int main(){
	int i;
	srand(time(NULL));
	cellule_t *tete=NULL;
   cellule_t *new=Creer_liste_alea(10,10);
	for(i=1;i<=10;i++){
		tete=Inserer_fin_it(i,tete);
	}
	Afficher_liste_int(tete);
	printf("La liste est elle ordonnée ?\n%d\n",Est_un_ensemble_it(tete));
	Afficher_liste_int(new);
	printf("La liste est elle ordonnée ?\n%d\n",Est_un_ensemble_rec(new));
	new=Trier_liste_selection(new);
	Afficher_liste_int(new);
	new=Eliminer_doublonsV2(new);
	Afficher_liste_int(new);
	printf("La liste est elle ordonnée ?\n%d\n",Est_un_ensemble_it(new));
	new=Liberer_liste(new);
	tete=Liberer_liste(tete);
	return 0;
}
