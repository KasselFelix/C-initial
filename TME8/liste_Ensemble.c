#include "liste_entiers.h"
#include <stdlib.h>

cellule_t* liste_vers_ensemble(cellule_t* liste){
	liste=Trier_liste_selection(liste);
	liste=Eliminer_doublons(liste);
	return liste;
}

int Est_un_ensemble_it(cellule_t *liste){
	if(liste==NULL){
		return 1;
	}
	while(liste->suivant){
		if(liste->donnee >= liste->suivant->donnee){
			return 0;
		}
		liste=liste->suivant;
	}
	return 1;
}

int Est_un_ensemble_rec(cellule_t *liste){
	if (liste == NULL || liste->suivant == NULL){return 1;}
	if(liste->donnee >= liste->suivant->donnee){return 0;}
	return Est_un_ensemble_rec(liste->suivant);
}

cellule_t *union_E_it(cellule_t *l1, cellule_t *l2){
	cellule_t *cell1 = l1, *cell2 = l2, *res = NULL;
	int v;
	while ((cell1 != NULL) && (cell2 != NULL)){
		if ((cell1->donnee > cell2->donnee)){
			v = cell2->donnee;
			cell2 = cell2->suivant;
		}else if((cell1->donnee<cell2->donnee)){
			v = cell1->donnee;
			cell1 = cell1->suivant;
		}else if(cell1->donnee == cell2->donnee){
			v=cell1->donnee;
			cell1 = cell1->suivant;
			cell2 = cell2->suivant;
		}
		res = Inserer_fin_it(v, res);
	}
	while((cell1==NULL)&&(cell2!=NULL)){
		res = Inserer_fin_it(cell2->donnee,res);
		cell2 = cell2->suivant;
	}
	while((cell2==NULL)&&(cell1!=NULL)){
	res = Inserer_fin_it(cell1->donnee,res);
	cell1 = cell1->suivant;
	}
	return res;
}

cellule_t *union_E_rec(cellule_t *l1, cellule_t *l2){
	if ((l1 == NULL) && (l2 == NULL))
		return NULL;
	if (l1 == NULL)
		return Inserer_tete(l2->donnee, union_E_rec(l1, l2->suivant));
	if (l2 == NULL)
		return Inserer_tete(l1->donnee, union_E_rec(l1->suivant, l2));
	if (l1->donnee > l2->donnee)
		return Inserer_tete(l2->donnee, union_E_rec(l1, l2->suivant));
	if (l2->donnee > l1->donnee)
		return Inserer_tete(l1->donnee, union_E_rec(l1->suivant, l2));
	if (l1->donnee == l2->donnee)
		return Inserer_tete(l1->donnee, union_E_rec(l1->suivant, l2->suivant));
	return 0;
}

cellule_t* inter_E_it(cellule_t* l1, cellule_t* l2){
	cellule_t* liste=NULL;
	if(l1 == NULL || l2 == NULL){
		return NULL;
	}
	while(l1 != NULL && l2 != NULL){
		if(l1->donnee == l2->donnee){
			liste=Inserer_tete(l1->donnee,liste);
			l1=l1->suivant;
			l2=l2->suivant;
		}
		else if(l1->donnee < l2->donnee){
			l1=l1->suivant;
		}
		else{
			l2=l2->suivant;
		}
	}
	return liste;
}

cellule_t* inter_E_rec(cellule_t* l1, cellule_t* l2){
	cellule_t* liste=NULL;
	if(l1 == NULL || l2 == NULL){
		return NULL;
	}
	if(l1->donnee == l2->donnee){
		liste=inter_E_rec(l1->suivant,l2->suivant);
		liste=Inserer_tete(l1->donnee,liste);
	}
	else if(l1->donnee < l2->donnee){
		liste=inter_E_rec(l1->suivant,l2);
	}
	else{
		 liste=inter_E_rec(l1,l2->suivant);
	}
	return liste;	
}

cellule_t *soustraction_E(cellule_t *l1, cellule_t *l2){
	cellule_t *res = Dupliquer_liste(l1);
	cellule_t *cell2 = l2;
	while (cell2 != NULL){
		res = Supprimer_element_it(cell2->donnee,res);
		cell2 = cell2->suivant;
	}
	return res;
}

cellule_t *soustraction_E_it_efficace(cellule_t *l1, cellule_t *l2){
	cellule_t *cell1 = l1;
	cellule_t *cell2 = l2;
	cellule_t *res = NULL;
	while ((cell1 != NULL) && (cell2 != NULL)){
		if (cell1->donnee < cell2->donnee){
			res = Inserer_fin_it(cell1->donnee, res);
			cell1=cell1->suivant;
		}
		else if (cell1->donnee == cell2->donnee){
				cell1 = cell1->suivant;
		}
		else if (cell1->donnee > cell2->donnee){
				cell2 = cell2->suivant;
		}
	}
	while (cell1 != NULL){
		res = Inserer_fin_it(cell1->donnee, res);
		cell1 = cell1->suivant;
	}
	return res;
}

cellule_t *soustraction_E_rec(cellule_t *l1, cellule_t *l2){
	cellule_t *res;
	if (l1 == NULL)
		return NULL;
	if (l2 == NULL){
		return res=Inserer_tete(l1->donnee, soustraction_E_rec(l1->suivant, l2));
	}
	if (l1->donnee < l2->donnee){
		return res=Inserer_tete(l1->donnee, soustraction_E_rec(l1->suivant, l2));
	}
	if (l2->donnee < l1->donnee){
		return res=Inserer_tete(l1->donnee, l2->suivant);
	}
	if (l1->donnee == l2->donnee){
		return res=soustraction_E_rec(l1->suivant, l2->suivant);
	}
	return 0;
}

cellule_t* xor_E(cellule_t* l1, cellule_t* l2){
	cellule_t *p1;
	cellule_t *p2;
	cellule_t *res; 
	p1=union_E_it(l1,l2);
	p2=inter_E_it(l1,l2);
	res=soustraction_E(p1,p2);
	Liberer_liste(l1);
	Liberer_liste(l2);
	return res;
}

int inclusion_E(cellule_t* l1, cellule_t* l2){
	cellule_t *p;
	p=inter_E_rec(l1,l2);
	if(listes_identiques(p,l1)){
		p=Liberer_liste(p);
		return 1;
	}
	p=Liberer_liste(p);
	return 0;
}

