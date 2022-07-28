#include <assert.h>
#include <stdio.h>

int surface(int l, int L){
    return l*L;

}

int main(){
	assert(surface(0,0)==0);
	assert(surface(0,20)==0);
	assert(surface(20,0)==0);
	assert(surface(1,1)==1);
	assert(surface(10,5)==50);
	return 0;
}
