#include <stdio.h>

void affichecroix(int n, char c){

	int i,j;

	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
            	if(i==j) {
            		printf("%c",c);
            	}else{
            		if(j==n-1-i) {
            			printf("%c",c);
            		}else{
             			printf(" ");
             		}
            	}
            	
		}
		printf("\n");
	}

}

void choisir_dessiner(){
	char c;
	int n;
	scanf("%c", &c);
	scanf("%d", &n);
	affichecroix(n,c);
}


int main(){
	
	choisir_dessiner();
	return 0;
}


