#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct _cellule_t cellule_t;
struct _cellule_t{
	int donnee;
	cellule_t*suivant;
};


void Afficher_liste_int(cellule_t *liste){
	cellule_t *cell = liste;
	while (cell != NULL) {
		printf("%d ", cell->donnee);
		cell = cell->suivant;
	}
	printf("\n");
}

int len(cellule_t* liste){
    int res=0;
    cellule_t *cell=liste;
    while(cell){
        res++;
        cell=cell->suivant;
    }
    return res;
}

int Existe(cellule_t *liste,int val){
    cellule_t *cell=liste;
    while(cell){
        if(cell->donnee==val){
            return 1;
        }
        cell=cell->suivant;
    }
    return 0;
}

cellule_t *Creer_cellule(int d){
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

cellule_t *Inserer_en_pos(int d, int pos , cellule_t *liste){
	cellule_t *p;
	cellule_t *tmp;
	p=Creer_cellule(d);
	if(liste==NULL || pos == 0){
			p->suivant=liste;
			return p;
	}
	tmp=liste;
	while(tmp->suivant!=NULL && pos>1){
		tmp=tmp->suivant;
		pos--;
	} 
	p->suivant=tmp->suivant;
	tmp->suivant=p;
	return liste;
}

cellule_t *Concatener_it(cellule_t *liste1, cellule_t *liste2){
	if(liste1 == NULL){
		return liste2;
	}
	if(liste2==NULL){
		return liste1;
	}
	cellule_t *liste=liste1;
	while(liste->suivant){
		liste=liste->suivant;
	}
	liste->suivant=liste2;
	return liste1;
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

cellule_t* Retourner_dernier_element(cellule_t* liste){
	if(liste==NULL){
		return NULL;
	}
	while(liste->suivant){
		liste=liste->suivant;
	}
	return liste;
}

cellule_t* Retourner_element_debut(int val, cellule_t *liste){
    cellule_t *cell=liste;
    while(cell){
        if(cell->donnee == val){
            return cell;
        }
        cell=cell->suivant;
    }
    return cell;
}

cellule_t* Retourner_element_fin(int val, cellule_t *liste){
    cellule_t *cell=liste;
    cellule_t *temp=NULL;
    while(cell){
        if(cell->donnee == val ){
            temp=cell;
        }
        cell=cell->suivant;
    }
    return temp;
}


void Modifier_element(int val, int pos,cellule_t* liste){
	int i=0;
	while(liste && i<pos){
		i++;
		liste=liste->suivant;
	}
	if(liste){
		liste->donnee=val;
	}
}

cellule_t* Liberer_liste(cellule_t* liste){
	cellule_t *tmp;
	while(liste !=NULL){
		tmp=liste->suivant;
		free(liste);
	liste=tmp;
	}
	return NULL;
}


cellule_t *Supprimer_element_it(int val, cellule_t *liste){
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

cellule_t *Supprimer_en_pos_it(int pos,cellule_t *liste){
	cellule_t *tmp;
	cellule_t *p;
	if(liste){
		return NULL;
	}
	if(pos==0){
		tmp=liste;
		liste=liste->suivant;
		free(tmp);
		return liste;
	}
	p=liste;
	while(p->suivant != NULL && pos > 1){
		p=p->suivant;
		pos--;
	}
	if(p->suivant!=NULL){
		tmp=p->suivant;
		p->suivant=tmp->suivant;
		free(tmp);
	}
	return liste;
}

cellule_t *maximum(cellule_t *liste){
	cellule_t *tmp=liste;
	while(liste){
		if(tmp->donnee < liste->donnee){
			tmp=liste;
		}
		liste=liste->suivant;
	}
	return tmp;
		
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


int nb_maximum(cellule_t *liste){
	int o_max=0;
	if(liste == NULL){
		return o_max;
	}
	int max=liste->donnee;
	while(liste){
		if(liste->donnee > max){
			max=liste->donnee;
			o_max=1;
		}
		else if(liste->donnee == max){
			o_max++;
		}
		liste=liste->suivant;
	}
	return o_max;
}

int Retourner_val_element_pos(int pos, cellule_t *liste){
	cellule_t *p=liste;
	while(pos<0 && p != NULL){
		p=p->suivant;
		pos--;
	}
	return p->donnee;
}


cellule_t *Trier_liste_selection( cellule_t *liste){
	cellule_t *max;
	cellule_t *l2=NULL;
	while(liste){
		max=maximum(liste);
		l2=Inserer_tete(max->donnee,l2);
		liste=Supprimer_element_it(max->donnee,liste);
	}
	return l2;
}

cellule_t *Eliminer_doublons(cellule_t *liste){
	cellule_t *tmp;
	if(liste==NULL || liste->suivant == NULL){
		return liste;
	}
	tmp=liste;
	while(tmp->suivant){
		if(tmp->donnee == tmp->suivant->donnee){
			tmp=Supprimer_en_pos_it(1,tmp);
		}else{
			tmp=tmp->suivant;
		}
	}
	return liste;
}

cellule_t *Eliminer_doublonsV2(cellule_t *liste){
    cellule_t *cell = liste, *tmp;
    while (cell->suivant != NULL){
        if (cell->suivant->donnee == cell->donnee){
            tmp = cell->suivant;
            cell->suivant = tmp->suivant;
            free(tmp);
        }else{
            cell = cell->suivant;
        }
    }
    return liste;
}

cellule_t *Creer_liste_alea(int val_max, int nb_val ){
	cellule_t *liste=NULL;
	
	while(nb_val>=1){
		liste=Inserer_fin_it(rand()%val_max,liste);
		nb_val--;
	}
	return liste;
}

int listes_identiques(cellule_t *l1, cellule_t *l2){
	while(l1 != NULL && l2 != NULL){
		if(l1->donnee!=l2->donnee){
			return 0;
		}
		l1=l1->suivant;
		l2=l2->suivant;
	}
	if((l1== NULL && l2 != NULL) || (l2 == NULL && l1 != NULL)){
	 return 0;
	}
	return 1;
}

int listes_identiques_rec(cellule_t *l1, cellule_t *l2){
	if (l1==NULL && l2==NULL){return 1;}
	if((l1== NULL && l2 != NULL) || (l2 == NULL && l1 != NULL)){return 0;}
	if(l1->donnee!=l2->donnee){return 0;}
	return listes_identiques(l1->suivant,l2->suivant);
}
