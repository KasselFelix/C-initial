#include <stdio.h>
#include <time.h>
#include <stdlib.h>

char choix_ordinateur(){
	
	int o=1+rand()%3;
	char *tab="Ciseaux";
	if(o==1){
		tab="Pierre";
		return *tab;
	}
	if(o==2){
		tab="Feuille";
		return *tab;
	}
	return *tab+1;			
}

int main(){
	srand(time(NULL));
	printf("%c\n",choix_ordinateur());
	return 0;
}

/*#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int choix_ordinateur(){
	
	int o=1+rand()%3;
	if(o==1){
		printf("Ciseaux\n");
		return o;
	}
	if(o==2){
		printf("Feuille\n");
		return o;
	}
	printf("Pierre\n");
	return o;			
}

int choix_joueur(){
	int j,i=0;
	do{
		printf("saisi\n");
		scanf("%d",&j);
		i++;
		if(j<=3 && j>=1){
			return j;
		}
	}while(i<3 && (j>=3 || j<=1));
	j=1+rand()%3;
	return j;
}
	
int main(){
	srand(time(NULL));
	int *j=choix_joueur();
	printf("j %d\n",*j);
	int *o=choix_ordinateur;
	printf("%d\n",*o);
	return 0;
}*/
