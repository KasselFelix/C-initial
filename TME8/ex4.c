#include<stdio.h>
#include<stdlib.h>
#include "liste_entiers.h"
#include "liste_Ensemble.h"



int main(){
	cellule_t* l1=NULL;
	cellule_t* l2=NULL;
	cellule_t* res;
	int i;
	for(i=0;i<10;i++){
		l1=Inserer_fin_it(i,l1);
	}
	for(i=0;i<10;i+=2){
		l2=Inserer_fin_it(i,l2);
	}
	Afficher_liste_int(l1);
	Afficher_liste_int(l2);
	printf("%d\n",inclusion_E(l2,l1));
	res=xor_E(l2,l1);
	Afficher_liste_int(res);
	l1=Liberer_liste(l1);
	l2=Liberer_liste(l2);
	return 0;
}
