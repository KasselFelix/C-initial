#include <stdio.h>
#include <stdlib.h>
#define taille1 10
#define taille2 15

int *tri(int tab1[], int tab2[]){
	int i1=0,i2=0,ir=0;
	int *tabres=malloc((taille1+taille2)*sizeof(int));
	while(i1<taille1 && i2<taille2){
		if(tab1[i1]<tab2[i2]){
			tabres[ir]=tab1[i1];
			ir++;
			i1++;
		}else{
			tabres[ir]=tab2[i2];
			ir++;
			i2++;
		}	
	}
	if (i2!=taille2 || i1 != taille1){
		if (i2==taille2){
			for(;i1<taille1;ir++){
				tabres[ir]=tab1[i1];
				i1++;
			}
		}else{
			for(;i2<taille2;ir++){
				tabres[ir]=tab2[i2];
				i2++;
			}
		}
	}
	return tabres;
}


void affiche(int tabres[]){
	int i;
	for(i=0;i<(taille1+taille2);i++){
		printf("%d\t",tabres[i]);
	}
	printf("\n");
}


int main(){
	int tab1[taille1]={1,3,5,7,9,11,13,15,17,19};
	int tab2[taille2]={2,4,6,8,10,12,14,16,18,20,21,22,23,24,25};
	int *tabres=tri(tab1,tab2);
	affiche(tabres);
	free(tabres);
	return 0;
}
