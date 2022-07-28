#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void affiche_lettre(char *chaine){
	for(;*chaine!= '\0';chaine++){
		if((*chaine>='A' && *chaine<='Z') || (*chaine>='a' && *chaine<='z')){
			printf("%c\t",*chaine);
		}
	}
	printf("\n");
}

void construction(char *chaine,char *newChaine){
	int i;
	for(i=0;*(chaine+i) != '\0';i++){
		if((*(chaine+i)>='A' && *(chaine+i)<='Z') || (*(chaine+i)>='a' && *(chaine+i)<='z')){
			*newChaine=*(chaine+i);
			newChaine++;
		}
	}
}

/*void *modification(char *chaine){
	char *p=chaine;
	int cpt;
	for(;*chaine != '\0';chaine++){
		while((*chaine<'A' && *chaine>'Z') || (*chaine<'a' && *chaine>'z')){
			p=chaine;
			while(*p != '\0'){
				*chaine=*(chaine+1);
				p++;
			}
		}
	}
}*/


void affiche(char *chaine){
	for(;*chaine != '\0';chaine++){
		printf("%c\t",*chaine);
	}
	printf("\n");
}


int main(){
	char *chaine="abcdef+++gh5";
	char newChaine[strlen(chaine)];
	
	affiche_lettre(chaine);
	construction(chaine,newChaine);
	affiche(newChaine);
	return 0;
}

