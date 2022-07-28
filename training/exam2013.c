#include <stdio.h>
#include <stdlib.h>

/*void f(char *tab){*/
/*	int i=0;*/
/*	while(*(tab+i) != '\0'){*/
/*		*(tab+i)=2*(*(tab+i));*/
/*		i++;*/
/*	}*/
/*	*/
/*}*/

/*int a = 1, b = 2, c = 3;*/

/*int f(int x, int y,int *pa, int b) {*/
/*	*pa = (x + y)*b;*/
/*	return x - y;*/
/*}*/

/*void g(int u, int v, int *pa, int *pb, int c) {*/
/*	*pb = c * f(u+v,*pa, pa, *pb);*/
/*}*/

int valeur(int grille[][9],int c,int l){
	return grille[l][c];
}

void modifie(int grille[][9],int c,int l,int val){
		grille[l][c]=val;
}

int verifie_ligne(int grille[][9],int l, int v){
	int j;
	for(j=0;j<9;j++){
		if(grille[l][j]==v){
			return 0;
		}
	}
	return 1;
}

int verifie_colonne(int grille[][9],int c, int v){
	int i;
	for(i=0;i<9;i++){
		if(grille[i][c]==v){
			return 0;
		}
	}
	return 1;
}

int verifie_sous_carre(int grille[9][9],int l, int c,int v){
	//coin haut gauche sous carree
	int dl=(l/3)*3;
	int dc=(c/3)*3;
	int i,j;
	for(i=dl;i<dl+3;i++){
		for(j=dc;j<dc+3;j++){
			if(grille[i][j]==v){
				return 0;
			}
		}
	}
	return 1;
}

int verifie(int grille[][9], int l, int c, int v){
	if(grille[l][c]==0 && ((verifie_ligne(grille,l,v)==1  && verifie_colonne(grille,c,v)==1) && verifie_sous_carre(grille,l,c,v)==1)){
		return 1;
	}
	return 0;
}



int resout(int grille[9][9],int i,int j){
	int n;
	int o=grille[i][j];
	for(n=1;n<=9;n++){
		if(verifie(grille,i,j,n)==1 || grille[i][j]!=0){
			if(grille[i][j]==0){
         	grille[i][j]=n;
			}
			if(i==8 && j==8){
				return 1;
			}else if(j==8){
				return resout(grille,i+1,0);
			}else{
				return resout(grille,i,j+1);
			}
			grille[i][j]=o;
		}
	}
	return 0;
}



int main() {
	/*	int a = 1, b = 2, c = 3;*/
	/*	g(1, 2,&a,&b,c);*/
	/*	printf("a=%d, b=%d, c=%d\n", a, b, c);*/
	int grille[9][9]={{0,1,0,6,0,7,0,0,4},
							{0,4,2,0,0,0,0,0,0},
							{8,7,0,3,0,0,6,0,0},
							{0,8,0,0,7,0,0,2,0},
							{0,0,0,8,9,3,0,0,0},
							{0,3,0,0,6,0,0,1,0},
							{0,0,8,0,0,6,0,4,5},
							{0,0,0,0,0,0,1,7,0},
							{4,0,0,9,0,8,0,6,0}};
							
	printf("%d\n",verifie_sous_carre(grille,7,7,1));

	if (resout(grille,0,0)) {
		printf("Solution\n");
	} else {
		printf("Pas de solution\n");
	}


	int i,j;
	for(i=0;i<9;i++){
		for(j=0;j<9;j++){
			printf("%d\t",grille[i][j]);
		}
		printf("\n");
	}
	return 0;
}
