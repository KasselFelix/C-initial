#include <math.h>
#include <assert.h>
#include <stdio.h>

float valeur_absolue(float n){
	return sqrt(n*n);
}

int egal_eps(float n1, float n2, float n3){
	
	if(valeur_absolue(n1-n2) <= n3){
		return 1;
	}
	return 0;
}

int main(){
	assert(egal_eps(3.8,3.2,0.3)==0);
	assert(egal_eps(2.43,2.465,0.1)==1);
	assert(egal_eps(2.465,2.4658,0.001)==1);
	assert(egal_eps(2.46,2.465,0.001)==0);
	return 0;
} 
