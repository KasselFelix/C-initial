#include <stdio.h>
#define KMIN 1
#define KMAX 10
int sommeDiviseurs(int n){
	int s=0;
	int i;
	for(i=1;i<n;i++){
		if(n%i==0){
			s=s+i;
		}
	}
	return s;
}

int k_parfait(int n, int k){
	if(sommeDiviseurs(n)+n==k*n){
		return 1;
	}
	return 0;
}

int trouver_k_parfait(int n){
	int i;
	for(i=KMIN;i<=KMAX;i++){
		if (k_parfait(n,i)==1){
			return i;
		}
	}
	return -1;
}

int main(){
	int n=10,k=2; 
	printf("%d\n%d\n%d\n",sommeDiviseurs(n),k_parfait(n,k),trouver_k_parfait(n));
	return 0;
	
}

