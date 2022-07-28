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

char *construction(char *chaine){
	char *newChaine=malloc(20*sizeof(char));
	char *p=newChaine;
	while(*chaine != '\0'){
		if((*chaine>='A' && *chaine<='Z') || (*chaine>='a' && *chaine<='z')){
			*p=*chaine;
			p++;
		}
		chaine++;
	}
	
	return newChaine;
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
	char *newChaine=construction(chaine);
	affiche(newChaine);
	free(newChaine);
	return 0;
}

