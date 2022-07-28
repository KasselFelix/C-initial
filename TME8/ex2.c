#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include "liste_entiers.h"


int main(){
	srand(time(NULL));
	cellule_t *l1=NULL;
	cellule_t *l2=NULL;
	cellule_t *l3=NULL;
	cellule_t *l4=NULL;
	
	printf("l1 :");
	l1=Creer_liste_alea(10, 10);
	Afficher_liste_int(l1);
	printf("l2 :");
	l2=Creer_liste_alea(10, 10);
	Afficher_liste_int(l2);
	printf("%d\n",listes_identiques(l1,l2));
	
	l3=Inserer_fin_it(1,l3);
	printf("l3 :");
	Afficher_liste_int(l3);
	
	l4=Inserer_fin_it(1,l4);
	printf("l4 :");
	Afficher_liste_int(l4);
	
	printf("%d\n",listes_identiques(l3,l4));
	l1=Liberer_liste(l1);
	l2=Liberer_liste(l2);
	l3=Liberer_liste(l3);
	l4=Liberer_liste(l4);
	return 0;
}
