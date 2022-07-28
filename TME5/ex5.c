#include <stdio.h>
#include <string.h>

int est_deb(char *chaine1, char *chaine2){
	if(*chaine1 == '\0'){return 1;}
	if(*chaine1 != *chaine2){return 0;}
	return est_deb(chaine1+1,chaine2+1);
}


int est_incluse(char *chaine1, char *chaine2){
	
	if(*chaine1=='\0'){return 0;}
	if(*chaine1==*chaine2){
		if(est_deb(chaine1,chaine2)==1){
			return 1;
		}
	}
	return est_incluse(chaine1+1,chaine2+1);
} 






int main(){
	char *chaine1="lp";
	char *chaine2="alphabet";
	//printf("%d\n",est_deb(chaine1,chaine2));
	printf("%d\n",est_incluse(chaine1,chaine2));
	return 0;
}
