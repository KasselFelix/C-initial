#include <stdio.h>
#include <math.h>
#include <assert.h>

int valeur_absolue(int n){
    return sqrt(n*n);
}

int signeSomme(int n1, int n2){
    if (valeur_absolue(n1)== valeur_absolue(n2) && n1 != n2){
    		return 0;
    }
    if (n1 < n2 && valeur_absolue(n1) > valeur_absolue(n2)){
            return -1;
    }
    if (n1 > n2 && valeur_absolue(n1) < valeur_absolue(n2)){
            return -1;
    }
    if (n1==n2 && valeur_absolue(n1) != n2){
    	return -1;
    }
    return 1;
}

int main(){
    assert(signeSomme(-2,-2)==-1);
    assert(signeSomme(-2,-1)==-1);
    assert(signeSomme(-2,1)==-1);
    assert(signeSomme(-1,-2)==-1);
    assert(signeSomme(-1,-1)==-1);
    assert(signeSomme(1,-2)==-1);
    assert(signeSomme(-2,2)==0);
    assert(signeSomme(-1,1)==0);
    assert(signeSomme(1,-1)==0);
    assert(signeSomme(2,-2)==0);
    assert(signeSomme(2,2)==1);
    assert(signeSomme(2,1)==1);
    assert(signeSomme(2,-1)==1);
    assert(signeSomme(1,2)==1);
    assert(signeSomme(1,1)==1);
    assert(signeSomme(-1,2)==1);
    return 0;
}
