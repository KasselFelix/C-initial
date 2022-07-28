#include <stdio.h>
#include <assert.h>

int plusGrand(int n1, int n2, int n3){
	if (n1 >= n2 && n1 >= n3){	
		return n1;
	}else{
		if(n2 >= n3){
			return n2;	
		}else{
			return n3;
		}
	}
	
}

int main(){
	int n1=3,n2=5,n3=1,n4=4,n5=2;
	assert(plusGrand(1,2,3)==3);
	assert(plusGrand(3,2,1)==3);
	assert(plusGrand(2,3,1)==3);
	assert(plusGrand(1,3,3)==3);
	printf("Le plus grand parmis %d,%d,%d,%d et %d est %d.\n",n1,n2,n3,n4,n5,plusGrand(plusGrand(n1,n2,n3),n4,n5));
	return 0;
}

