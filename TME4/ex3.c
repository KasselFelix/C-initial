#include <stdio.h>
#define TAILLE 20
#define FIN 7

int indiceInsert(int tab[], int nbel, int el){
	int i;
	if(nbel+1>TAILLE)
		return -1;
	for(i=0;i<nbel;i++){
		if(el==tab[i])
			return -1;
		if(el<tab[i]){
			return i;
    		}
	}
	return i;
}

int insertElt(int el,int tab[],int *nbel,int indice){
	int i;
	if (*nbel<TAILLE && indice!=-1){
		printf("indice : %d\n",indice);
		for(i=0;i<*nbel-indice;i++){
				tab[*nbel-i]=tab[*nbel-1-i];
	    	}
	    	tab[indice]=el;
	    	(*nbel)++;
		return 1;
	}
	printf("%d est deja present\n",el);
	return 0;
}

void affiche(int tab[]){
	int i;
	for(i=0;i<TAILLE;i++){
		printf("%d\t",tab[i]);
	}
	printf("\n");
}


int main(){
	int nbel=6,i=0;
	int tab[TAILLE]={2,3,5,7,9,11};
	int tabE[FIN]={1,4,6,8,10,11,13};
	while (i<FIN){
		affiche(tab);
		printf("element : %d\n",tabE[i]);
		insertElt(tabE[i],tab,&nbel,indiceInsert(tab,nbel,tabE[i]));
		i++;
	}
	affiche(tab);
	return 0;
}



