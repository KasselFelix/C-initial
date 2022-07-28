#include <stdio.h>

float multi(int n1, float n2){
	return n1 * n2;
}

int main(){
	int op1=2;
	float op2=4.0;
	printf("%d * %f = %f\n",op1,op2,multi(op1,op2));
	return 0;
}
