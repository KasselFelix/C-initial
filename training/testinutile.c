#include <stdio.h>

int main(){
	int p=75,t=168;
	float IMC,tm;
	tm=t/100.0;
	
	IMC=p/(tm*tm);

	printf("IMC : %f\n",IMC);
	
	if (IMC <18.5){
		printf("vous etes en dessous de la corpulence moyenne\n");
		}else{
			if (IMC>25){
				printf("vous etes au dessus de la corpulence moyenne\n");
				}else{
					printf("vous etes de corpulence moyenne\n");
				}
	}
	return 0;
}
