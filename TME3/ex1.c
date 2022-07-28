#include <stdio.h>
#include <time.h>
#include <stdlib.h>


void pos_neg_zero(int val , int *cpt_plus,int *cpt_moin,int *cpt_zero){
	
	if (val>0){
		(*cpt_plus)++;
	}else{
		if(val==0){
			(*cpt_zero)++;
		}else{
			(*cpt_moin)++;
		}
	}
}

int main(){
	
	int i,val=0,cpt_plus=0,cpt_zero=0,cpt_moin=0;
	
	srand(time(NULL));
	for(i=0;i<50;i++){
		val=-20+rand()%41;
		pos_neg_zero(val,&cpt_plus, &cpt_moin, &cpt_zero);
	 }
	printf("pos %d\nneg %d\nzero %d\n",cpt_plus,cpt_moin,cpt_zero);
	return 0;
}
	
			
