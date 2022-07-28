#include <stdio.h>

void permute(int *a, int *b){
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}

void permute_circulaire(int *a, int*b, int *c){
	permute(a ,c);
	permute(a ,b);
}

int main(){
	int a,b,c;
	a=10,b=20,c=30;
	printf("%d %d %d\n",a,b,c);
	permute_circulaire(&a,&b,&c);
	printf("%d %d %d\n",a,b,c);
	return 0;
}			
