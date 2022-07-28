#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void score(int *cpt,int *spare, int *strike,int *nb, int *renv, int *lancer, int *i){
	*nb=*nb+*renv;
	if(*strike==1 && *i!=11){
		*cpt=*cpt+*renv;
	}
	if(*spare==1 && *i!=11){
		*cpt=*cpt+*renv;
	}
	if (*lancer==1 && *renv==10){
		(*strike)++;
	}
	if (*lancer>1 && *nb==10 && *strike==0){
		*spare=*spare+1;
	}
	*cpt=*cpt+*renv;
}

void tour( int *strike, int *spare, int *cpt, int *max,int *i){
	
	int lancer,tmp=0,nb=0,renv=0;
	
	for(lancer=1;lancer<=*max;lancer++){
		printf("lancer : %d\n",lancer);
		
		if(*i!=11){
			tmp=renv;
		}
		if(*i==11){
			if(*strike==1 || *spare==1){
				tmp=0;
				nb=0;
				*strike=0;
				*spare=0;
			}
		}
		renv=rand()%(11-tmp);
		
		printf("quilles renversée : %d\n",renv);

		score(cpt,spare,strike,&nb,&renv,&lancer,i);
	
		
		printf("strike : %d\n",*strike);
		printf("spare : %d\n",*spare);
		printf("score : %d\n",*cpt);

	}
}

void jeu(){
	int i,strike=0,spare=0,cpt=0,max=2;
	for(i=1;i<=10;i++){
	printf("tour : %d\n",i);
		strike=0;
		spare=0;
		tour(&strike,&spare,&cpt,&max,&i);
	
	}
	
	if(strike==1){
	
		printf(" lancer bonus :\n");
		max=2;
		tour(&strike,&spare,&cpt,&max,&i);
	}
	if(spare==1){
	
		printf("lancer bonus :\n");
		max=1;
		tour(&strike,&spare,&cpt,&max,&i);
	}
}

int main(){
	srand(time(NULL));
	jeu();
	return 0;
}
