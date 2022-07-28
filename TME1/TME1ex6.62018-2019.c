#include <stdio.h>
#include <assert.h>

int signeProduit(int n1, int n2){
	if(n1==0 || n2==0){
		return 0;
	}else{
		if (n1<0 && n2<0){
			return 1;
		}else{
			if(n1<0 || n2<0){
				return -1;
			}else{
				return 1;
			}
		}
	}
}

int main(){
	assert(signeProduit(1,2)==1);
	assert(signeProduit(-2,1)==-1);
	assert(signeProduit(-2,-1)==1);
	assert(signeProduit(-2,0)==0);
	return 0;
}
