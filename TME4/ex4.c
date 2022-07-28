#include <stdio.h>
#include <stdlib.h>

void placeElt(float tab[],int i){
    float temp=tab[i];
    int j=i;
    while(temp<tab[j-1] && j!=0){
        tab[j]=tab[j-1];
        j--;
    }
    tab[j]=temp;
}

void affiche(float tab[]){
	int i;
	for(i=0;i<4;i++){
		printf("%f\t",tab[i]);
	}
	printf("\n");
}

int main(){
    int i;
    float tab[4]={6.0,3.0,4.0,1.0};
    affiche(tab);
    for(i=1;i<4;i++){
        placeElt(tab,i);
    }
    affiche(tab);
    return 0;
}
