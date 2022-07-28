#include <stdio.h>
#include <assert.h>

int premier(int n){
	int i;
	for(i=2;i<n;i++){
		if (n%i==0){
			return 0;
		}
	}
	return 1;
}

void  listeNombePremiers(int max){
	int i;
	for(i=2;i<=max;i++){
		if (premier(i)==1){
			printf("%d\n",i);
		}
	}
	
}

int main(){
	assert(premier(3)==1);
	assert(premier(59)==1);
	listeNombePremiers(100);
	return 0;
}

