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

int main(){
	cellule_t *liste=NULL;
	cellule_t *liste2=NULL;
	cellule_t *grand;
	int i;
	for(i=0;i<5;i++){
		liste=Inserer_fin_it(i,liste);
		liste2=Inserer_fin_it(i,liste2);
	}
	
	liste=Inserer_fin_it(5,liste);
	liste=Inserer_fin_it(5,liste);
	Concatener_it(liste,liste2);
	
	afficher(liste);
	printf("il y a %d occurences\n",nb_occurences(5,liste));
	printf("Est-ce que tous les element sont supérieur à notre valeur(1=vrai)(0=faux): %d \n",tous_plus_grand(3,liste));
	printf("La valeur en position %d est %d\n",2,Retourner_val_element_pos(2,liste));
	grand=maximum(liste);
	printf("%d\n",grand->donnee);
	printf("il y a %d occurence max\n",nb_maximum(liste));
	
	return 0;
}
